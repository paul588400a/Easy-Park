#include "stdafx.h"

void goin()
{
     char carNo[80];
     int check=0;
     int confirm=0;
     int i;
     int ctrl;
     
     
     while(check==0)
     {
      Clean;
      printf(goin_pic);
                    
      printf("�п�J�����s���G");
      scanf("%s",carNo);
      FLUSH;
            while(confirm==0)
            {
                 Confirm:
                     
                 printf("�T�{\"1\"���s��J\"0\"�^�D���\"3\" : ");
                 if((scanf("%d",&confirm)) != 1)
                 {
                      FLUSH;
                      goto Confirm;
                 }
                 else if(confirm == 0) 
                      break;
                 else if(confirm == 1)
                 {
                      check = 1;
                 }
                 else if(confirm == 3)
                      return;
                 else goto Confirm;
            }
           
           if(check == 1)
           {
                ctrl = provRePark(carNo);
                if(ctrl==1)
                {
                     printf("����!! ���P���X����!!\n\n�Ы����N��^�D���.. ");
                     getch();
                     break;
                }
                
                Clean;
                printf("�@���i���������@!!\n\n");
                printf("�@�����P�s�� : %s\n",carNo);
                timmer_park(carNo);
                
                picture1();
                    
                printf("�Ы����N��^�D���..");
                getch();
           }
           
     }
     
}

void goout()
{     
     char carNo[80];
     int check=0;
     int confirm=0;
     int i;
     
       //�ˬd���������O�_"�S����" 
     FILE *fpark;
     int parkNum = 0;
     int a;
     
     Clean;
     
     if(fpark = fopen("Parking.DAT","r")==NULL)
     {
          fpark = fopen("Parking.DAT","a");
          fclose(fpark);
     }
     fpark = fopen("Parking.DAT","r");
     while(fscanf(fpark,"%*[^\n]\n%*[^\n]\n%u\n\n",&a) != EOF)
     {
          parkNum++;
     }
     
     fclose(fpark);
     
     if(parkNum==0)
     { 
          printf("���������èS�����󨮽�!!\n\n");
          printf("�Ы����N��^�D���..");
          getch();
          return;
     }//�ˬd���������O�_"�S����" 
      
     
     while(check==0)
     {
          Clean;
          printf(goout_pic);
      
          printf("�п�J�����s���G");
          scanf("%s",carNo);
          FLUSH;
      
          while(confirm==0)
          {
               Confirm:
               printf("�T�{\"1\"���s��J\"0\"�^�D���\"3\" : ");
               if((scanf("%d",&confirm)) != 1)
               {
                    FLUSH;
                    goto Confirm;
               }
               else if(confirm == 0) break;
               else if(confirm == 1)
               {
                    check = 1;
               }
               else if(confirm == 3) return;
               else goto Confirm;
          }
     }
      
     timmer_out(carNo);
      
     printf("\n�Ы����N��^�D���..");
     getch();
     
}

void alter_price()
{
     int space, price;
     int confirm = 0;
     int checkNum;
     FILE* fp;
     fp = fopen("Init.DAT","r");
     
     fscanf(fp,"%d %d",&space,&price);
     fclose(fp);
     
     Confirm:
             
     Clean;
     
     printf("�ثe���O�з� : �C�b�p�� %d��\n(�����b�p�ɪ̥H�b�p�ɭp)\n\n",price);
     
     printf("�O�_��怜�O���B? \n");
     
     while(confirm==0)
     {
           printf("�T�{���\"1\" \"�^�D���\"0\" : ");
           if((scanf("%d",&confirm)) != 1)
           {
                  FLUSH;
                  goto Confirm;
           }
                  else if(confirm == 0) return;
                  else if(confirm == 1)
                  {
                          checkNum = 1;
                  }
                  else goto Confirm;
     }
     
     printf("\n�п�J�s�����O���B : ");
     while(checkNum == 1)
     {
            if(scanf("%d",&price) != 1)
            {
                   printf("��J���~�A�п�J����� : ");
                   FLUSH;
            }
            else if(price<=0) continue;
            else checkNum = 2;
     }
     
     fp = fopen("Init.DAT","w");
     fprintf(fp,"%d %d", space, price);
     fclose(fp);
     
     Clean;
     printf("��粒��!!\n");
     printf("�ثe���O�з� : �C�b�p�� %d��\n(�����b�p�ɪ̥H�b�p�ɭp)\n\n",price);
     
     printf("\n�Ы����N��^�D���..");
     getch();
}
