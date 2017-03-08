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
    printf("�@�������ɶ� : %s\n",str);
    fprintf(fp,"%s\n%s\n%u\n\n",carNo , str, a);
    
    fclose(fp);
}


void timmer_out(char carNo[])
{
    struct tm *time_now;
    time_t secs_now;
    char str[80];
    int c_second;       //1970 01.01�ܤ�(�X����)����� 
    
    int i = 0;
    int max;            //��l��ƪ�����(�Y�̤j����+1) 
    
    int secUse;
    int price;
    int out = -1;       //���ӳQ�R������ƪ����� 
    
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
                          printf("���X���p�O������\n");
                          secUse = c_second - car[i].second;
                          printf("�i���ɶ� : %s\n",car[i].day);
                          printf("�X���ɶ� : %s\n",str);
                          
                          price = priceCount(secUse);
                          printf("���O%d��\n",price);
                          
                          fprintf(fh,"���P���X:%s\n�i���ɶ�:%s\n�X���ɶ�:%s\n���O���B:%d\n",carNo,car[i].day,str,price);
                          fclose(fh);
                          out = i;
                          
                          picture5();
                     }
                     i++;
                     max = i;
    }
    
    if(out == -1)
    {
           printf("����!! �����d�L�����P!!\n");
           return;
    }
    
    fclose(fp);
    fp = fopen("Parking.DAT","w");
    
    for(i = 0; i < max; i++)
        if(i != out) 
             fprintf(fp,"%s\n%s\n%d\n\n", car[i].no, car[i].day, car[i].second); 
             
    fclose(fp);
}
