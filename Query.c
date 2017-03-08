#include "stdafx.h"

int space_query()
{
    FILE *fpark;
    FILE *finit;
    
    int remain;
    int space;
    int parkNum = 0;
    int price;
    int a;
    
    if(fpark = fopen("Parking.DAT","r")==NULL)
    {
             fpark = fopen("Parking.DAT","a");
             fclose(fpark);
    }
    
    fpark = fopen("Parking.DAT","r");
    finit = fopen("Init.DAT","r");
    
    fscanf(finit,"%d %d", &space, &price);
    
    while(fscanf(fpark,"%*[^\n]\n%*[^\n]\n%u\n\n",&a) != EOF)
    {
            parkNum++;
    }
    
    fclose(fpark);
    fclose(finit); 
    
    remain = space - parkNum;
    
    return remain;
}

void park_query()
{
     FILE *fpark;
     fpark = fopen("Parking.DAT","r");
     char str[80];
     int ctrl=0;
     
     system("cls");
     
     printf(park_query_pic);
     
     while(fscanf(fpark,"%[^\n]\n",str) != EOF)
     {
            ctrl++;
            
            switch(ctrl%3)
            {
                     case 0:
            printf("\n");
            break;
                     case 1:
            printf("%d.\n",ctrl/3+1);
            printf("車牌編號 : ");
            printf("%s\n",str);
            break;
                     case 2:
            printf("停車時間 : ");
            printf("%s\n",str);
            break;
            }
            
     }
     
     printf("請按任意鍵繼續..");
     getch();
     
         
}
