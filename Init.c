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
         
         printf("歡迎使用本系統！\n第一次登入請設定停車位數量 : ");
         while(checkNum == 0)
         {
              if(scanf("%d",&space)==NULL)
              {
              printf("輸入錯誤，請輸入正整數 : ");
              FLUSH;
              }
              else if(space<=0) printf("輸入錯誤，請輸入正整數 : ");
              else checkNum = 1;
         }
               
         printf("第一次登入請設定每半小時之收費金額 : ");
         while(checkNum == 1)
         {
              if(scanf("%d",&price)==NULL)
              {
              printf("輸入錯誤，請輸入正整數 : ");
              FLUSH;
              }
              else if(price<=0) printf("輸入錯誤，請輸入正整數 : ");
              else checkNum = 2;
         }
     fclose(check); 
         
     init = fopen("Init.DAT","w");
     fprintf(init,"%d %d",space, price);
         
     printf("設定完成!! \n共有停車位%d個\n每半小時收費%d元\n\n",space,price);
     fclose(init);
     
     printf("請按任意鍵繼續..");
     getch();
     }
     /*else
     {
     after = fopen("Init.DAT","r");
     fscanf(after,"%d %d",&price,&space);
     printf("設定完成!! \n共有停車位%d個\n每半小時收費%d元\n",space,price);
     }*/
}
