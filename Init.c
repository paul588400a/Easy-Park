#include "stdafx.h"
#define FLUSH while(getchar() != '\n')

void init()
{
    FILE *check;
    FILE *init;
    int price;
    int space=0;
    int k;
    int checkNum = 0;
    
    if((check = fopen("Init.DAT","r"))==NULL)
     {
         
         printf("�w��ϥΥ��t�ΡI\n�Ĥ@���n�J�г]�w������ƶq : ");
         while(checkNum == 0)
         {
              if(scanf("%d",&space)==NULL)
              {
              printf("��J���~�A�п�J����� : ");
              FLUSH;
              }
              else if(space<=0) printf("��J���~�A�п�J����� : ");
              else checkNum = 1;
         }
               
         printf("�Ĥ@���n�J�г]�w�C�b�p�ɤ����O���B : ");
         while(checkNum == 1)
         {
              if(scanf("%d",&price)==NULL)
              {
              printf("��J���~�A�п�J����� : ");
              FLUSH;
              }
              else if(price<=0) printf("��J���~�A�п�J����� : ");
              else checkNum = 2;
         }
     fclose(check); 
         
     init = fopen("Init.DAT","w");
     fprintf(init,"%d %d",space, price);
         
     printf("�]�w����!! \n�@��������%d��\n�C�b�p�ɦ��O%d��\n\n",space,price);
     fclose(init);
     
     printf("�Ы����N���~��..");
     getch();
     }
     /*else
     {
     after = fopen("Init.DAT","r");
     fscanf(after,"%d %d",&price,&space);
     printf("�]�w����!! \n�@��������%d��\n�C�b�p�ɦ��O%d��\n",space,price);
     }*/
}
