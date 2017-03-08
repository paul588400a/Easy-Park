#include "stdafx.h"

int provRePark(char carNo[])
{
    char No[80];
    char fileTime[80];
    int  timmer;
    int ctrl = 0;
    FILE *fp;
    fp = fopen("Parking.DAT","r");
    while(fscanf(fp,"%s\n%s\n%u\n\n",No , fileTime, &timmer)!=EOF)
    {
            if(strcmp(No,carNo)==0)
                    ctrl = 1;
    }
    
    if(ctrl==0)
        return 0;
    else
        return 1;
}
