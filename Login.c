#include "stdafx.h"

int main()
{
    init();
  
    int ctrl;
    int space;
    int logout = 0;
    int i;
  
    for(i=0;i<2;i++)
    {
        Clean;
        picture5();
        sleep(500);
    }
    
    system("COLOR 7");
    printf("�Ы����N���~��..");
    getch();
    
    Clean;
  
    while(logout == 0)
    {
        Clean;
        space = space_query();
        printf("\n!!�Ѿl %d�Ӱ�����!!\n\n",space);
        if(space==0)
        {
                printf("����w��!!\n\n");
        } 
  
        printf(main_String);
   
        if(scanf("%d",&ctrl)!=1)
        {
            FLUSH;
            ctrl = 0;
            continue;
        }
        else if(ctrl==1)
        {
            if(space==0)
            {
                printf("����w��!!"); 
                continue;
            }
            goin();
        }
        else if(ctrl == 2)
            goout();
            
        else if(ctrl == 3)
            park_query();
            
        else if(ctrl == 4)
            audit();
            
        else if(ctrl == 5)
            alter_price();
            
        else if(ctrl == 6)
            logout = Logout();
            
        else 
            continue;
   
    }  

    Clean;
    picture2(); 
    system("pause");	
    return 0;
}
