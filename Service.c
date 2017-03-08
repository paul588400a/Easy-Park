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
                    
      printf("請輸入車輛編號：");
      scanf("%s",carNo);
      FLUSH;
            while(confirm==0)
            {
                 Confirm:
                     
                 printf("確認\"1\"重新輸入\"0\"回主選單\"3\" : ");
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
                     printf("失敗!! 車牌號碼重覆!!\n\n請按任意鍵回主選單.. ");
                     getch();
                     break;
                }
                
                Clean;
                printf("　＊進場完成＊　!!\n\n");
                printf("　＊車牌編號 : %s\n",carNo);
                timmer_park(carNo);
                
                picture1();
                    
                printf("請按任意鍵回主選單..");
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
     
       //檢查停車場內是否"沒有車" 
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
          printf("停車場內並沒有任何車輛!!\n\n");
          printf("請按任意鍵回主選單..");
          getch();
          return;
     }//檢查停車場內是否"沒有車" 
      
     
     while(check==0)
     {
          Clean;
          printf(goout_pic);
      
          printf("請輸入車輛編號：");
          scanf("%s",carNo);
          FLUSH;
      
          while(confirm==0)
          {
               Confirm:
               printf("確認\"1\"重新輸入\"0\"回主選單\"3\" : ");
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
      
     printf("\n請按任意鍵回主選單..");
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
     
     printf("目前收費標準 : 每半小時 %d元\n(不足半小時者以半小時計)\n\n",price);
     
     printf("是否更改收費金額? \n");
     
     while(confirm==0)
     {
           printf("確認更改\"1\" \"回主選單\"0\" : ");
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
     
     printf("\n請輸入新的收費金額 : ");
     while(checkNum == 1)
     {
            if(scanf("%d",&price) != 1)
            {
                   printf("輸入錯誤，請輸入正整數 : ");
                   FLUSH;
            }
            else if(price<=0) continue;
            else checkNum = 2;
     }
     
     fp = fopen("Init.DAT","w");
     fprintf(fp,"%d %d", space, price);
     fclose(fp);
     
     Clean;
     printf("更改完畢!!\n");
     printf("目前收費標準 : 每半小時 %d元\n(不足半小時者以半小時計)\n\n",price);
     
     printf("\n請按任意鍵回主選單..");
     getch();
}
