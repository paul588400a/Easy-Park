#include "stdafx.h"

void audit()
{
     FILE* fp;
     char words[80];
     int i=0;
     
     if(fp = fopen("History.DAT","r")==NULL)
     {
             fp = fopen("History.DAT","w");
             fclose(fp);
     }
    
     fp = fopen("History.DAT","r");
     
     system("cls");
     
     printf(audit_pic); 
     
     while(fscanf(fp,"%[^\n] %*[\n]",words)!=EOF)
     {
             printf("%s\n",words);
             i++;
             if(i%4 == 0)
                     printf("\n");
     }
     
     printf("請按任意鍵繼續..");
     getch(); 
     
     fclose(fp);
}
