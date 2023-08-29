#include "application.h"
#include "patients.h"
#include "reserve.h"
#include "stdio.h"


void admin_mode(void)
{
    u32_t choise = 0;
    printf(space"Add new patient    --> 1\n");
    printf(space"Edit    patient    --> 2\n");
    printf(space"Reserve a slot     --> 3\n");
    printf(space"Cancel reservation --> 4\n");
    printf("Please enter your choise : ");
    scanf(" %i", &choise);
    switch(choise)
    {
    case 1:
        add_patient();
        break;
    case 2:
        edit_patient();
        break;
    case 3:
        reserve_slot();
        break;
    case 4:
        cancel_reserve();
        break;
    default:
        printf(space"Invalid input !!!\n");
        break;
    }
}

void user_mode(void)
{
    u32_t choise = 0;
    printf(space"Show patient record       --> 1\n");
    printf(space"Show today's reservations --> 2\n");
    printf("Please enter your choise : ");
    scanf(" %i", &choise);
    switch(choise)
    {
    case 1:
        view_patient();
        break;
    case 2:
        print_today_reservations();
        break;
    default:
        printf(space"Invalid input !!!\n");
        break;
    }
}

u32_t get_check_password(void)
{
    u32_t password = 0;
    u32_t trial = 0;
    u32_t ret_val = 0;//not correct
    while(trial < 3)
    {
        printf("Please enter password : ");
        scanf(" %i", &password);
        if(password == pass)
        {
            ret_val = 1;
            printf(space"Correct Password\n");
            break;
        }
        else
        {
            printf(space"Incorrect Password ... ");/*don't add \n*/
        }
        trial++;
    }
    return (ret_val);









}









