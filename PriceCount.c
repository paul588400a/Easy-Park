#include "stdafx.h"

int priceCount(int secUse)
{
       int perPrice;
       int s;
       int hour;
       int minute;
       int totalPrice;
       FILE *fp;
       fp = fopen("Init.DAT","r");
       
       fscanf(fp,"%d %d",&s , &perPrice);
       
       hour = secUse/3600;
       minute = (secUse%3600)/60;
       
       if(minute<=30)
       totalPrice = ((hour*2)+1)*perPrice;
       else
       totalPrice = ((hour*2)+2)*perPrice;
       
       printf("�@�@���F%d�p��,�S%d����\n",hour,minute);
       return totalPrice;
}
