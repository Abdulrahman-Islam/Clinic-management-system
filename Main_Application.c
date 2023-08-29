#include "application.h"
#include <stdio.h>



int main (void)
{
    u32_t choise = 1;//user mode
    u32_t password_correct = 1;//correct
    printf("--------------------------------- Clinic Management System ---------------------------------\n");
    while(password_correct)
    {                                                   
        printf("Please choose mode (admin:0 / user:1) : ");
        scanf(" %i", &choise);
        switch(choise)
        {
            case 0:
            password_correct = get_check_password();
            if(password_correct)
            {
                admin_mode();
            }
            else
            {
                break;
            }
            break;

            case 1:
            user_mode();
            break;

            default:
            printf(space"Invalid input !!!");
            break;
        }
    }
    printf("\n------------------------------------ Program End ------------------------------------\n");
    return (0);
}



//
//make functions parameter --> constant