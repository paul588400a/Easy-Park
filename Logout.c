#include "stdafx.h"

int Logout()
{
    int confirm = -1;
    
    while(confirm == -1)
    {
         Confirm:
         Clean;
         printf("�T�{�n�X\"1\"�@��^�D���\"0\" : ");
         if((scanf("%d",&confirm))==NULL)
         {
               FLUSH;
               goto Confirm;
         }
         else if(confirm == 1)
               return confirm;
         else if(confirm == 0)
               return confirm;
         else goto Confirm;
    
    }
}
