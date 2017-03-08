#include "stdafx.h"
#include "structure.h"

void timmer_park(char carNo[])
{
    struct tm *time_now;
    time_t secs_now;
    char str[80];
    long a;
    FILE *fp;
    fp = fopen("Parking.DAT","a");

    tzset();
    a =time(&secs_now);
    time_now = localtime(&secs_now);
    strftime(str, 80,"%Y/%m/%d %a %H:%M:%S--",time_now);
    printf("　＊停車時間 : %s\n",str);
    fprintf(fp,"%s\n%s\n%u\n\n",carNo , str, a);
    
    fclose(fp);
}


void timmer_out(char carNo[])
{
    struct tm *time_now;
    time_t secs_now;
    char str[80];
    int c_second;       //1970 01.01至今(出車時)的秒數 
    
    int i = 0;
    int max;            //原始資料的筆數(即最大索引+1) 
    
    int secUse;
    int price;
    int out = -1;       //應該被刪除之資料的索引 
    
    tzset();
    c_second = time(&secs_now);
    time_now = localtime(&secs_now);
    strftime(str, 80,"%Y/%m/%d %a %H:%M:%S--",time_now);
    
    FILE *fp;
    FILE *fh;
    fp = fopen("Parking.DAT","r");
    fh = fopen("History.DAT","a");

    while(fscanf(fp,"%s %[^\n] %d", car[i].no, car[i].day, &car[i].second)!=EOF)
    {
                     if(strcmp(car[i].no,carNo) == 0)
                     {
                          Clean;
                          printf("＊出場計費完成＊\n");
                          secUse = c_second - car[i].second;
                          printf("進場時間 : %s\n",car[i].day);
                          printf("出場時間 : %s\n",str);
                          
                          price = priceCount(secUse);
                          printf("收費%d元\n",price);
                          
                          fprintf(fh,"車牌號碼:%s\n進場時間:%s\n出場時間:%s\n收費金額:%d\n",carNo,car[i].day,str,price);
                          fclose(fh);
                          out = i;
                          
                          picture5();
                     }
                     i++;
                     max = i;
    }
    
    if(out == -1)
    {
           printf("失敗!! 場內查無此車牌!!\n");
           return;
    }
    
    fclose(fp);
    fp = fopen("Parking.DAT","w");
    
    for(i = 0; i < max; i++)
        if(i != out) 
             fprintf(fp,"%s\n%s\n%d\n\n", car[i].no, car[i].day, car[i].second); 
             
    fclose(fp);
}
