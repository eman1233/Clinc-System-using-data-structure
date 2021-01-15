#include "main.h"
int main(void)
{
    printf("Enter 0 to Admin mode \n");
    printf("Enter 1 to User  mode \n");

    printf("Enter Mode :");
    scanf("%d",&M);
    switch (M)
    {
       case AdminMode:
           {
               printf("                              You  are in Admin Mode\n");
               Admin_Mode();
               break;
           }

       case UserMode:
           {
                printf("                             You  are in User Mode\n");
                User_Mode();
                break;
           }

    }
    return 0;
}
