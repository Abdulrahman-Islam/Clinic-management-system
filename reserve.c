#include "reserve.h"
#include "STD_TYP.h"
#include "stdio.h"
#include "patients.h"/////////////////////////////////////////////////////////////////////

u32_t slots[5] = {0, 0, 0, 0, 0};

void reserve_slot(void)
{
    u32_t temp_id = 0;
    print_avaliable_slots();
    printf("Please enter Patient ID : ");
    scanf(" %i", &temp_id);
    if(check_id_exist(temp_id))/////////////////////////////////////////////////////////
    {
        u32_t temp_slot = 0;
        printf("Please enter number of slot to reserve : ");
        scanf(" %i", &temp_slot);
        if((!(temp_slot > 0)) && (!(temp_slot < 6)))
        {
            printf(space"Invalid slot number !!!");
        }
        else if(!check_slot_reserved(temp_slot))
        {
            slots[temp_slot - 1] = temp_id;
            printf(space"Slot reserved successfully");
        }
        else
        {
            printf(space"This slot [%i] reserved", temp_slot);
        }
    }
    else
    {
        printf(space"Invalid ID !!!");
    }
}

void cancel_reserve(void)
{
    u32_t temp_id = 0;
    u32_t temp_canceled = 0;
    printf("Please enter Patient ID : ");
    scanf(" %i", &temp_id);
    if(check_id_exist(temp_id))/////////////////////////////////////////////////////////i call function from other files.c
    {
        u32_t ctr = 0;
        for(ctr = 0; ctr < slots_num; ctr++)
        {
            if(slots[ctr] == temp_id)
            {
                slots[ctr] = 0;
                temp_canceled = 1;
                break;
            }
        }
        if(temp_canceled == 1)
        {
            printf(space"Reservation deleted successfully\n");
        }
        else
        {
            printf(space"No Reservation for deleting for ID : %i\n", temp_id);
        }
    }
    else
    {
        printf(space"This ID (%i) not recorded yet !!!\n", temp_id);
    }

}

int check_slot_reserved(u32_t slot)
{
    u32_t reserved = 1;//reserved
    if(!slots[slot - 1])
    {
        reserved = 0;//not reserved
    }
    return (reserved);
}

void print_avaliable_slots(void)
{
    u32_t ctr = 0;
    printf(space"Available Slots : \n");
    printf(space);
    for(ctr = 0; ctr < slots_num; ctr++)
    {
        if(!slots[ctr])
        {
            printf("   Slot %i   |", (ctr + 1));
        }
    }
    printf("\b \n"space);
    for(ctr = 0; ctr < slots_num; ctr++)
    {
        if(!slots[ctr])
        {
            if(ctr == 0)
            {
                printf(" 2:00->2:30 |");
            }
            if(ctr == 1)
            {
                printf(" 2:30->3:00 |");
            }
            if(ctr == 2)
            {
                printf(" 3:00->3:30 |");
            }
            if(ctr == 3)
            {
                printf(" 4:00->4:30 |");
            }
            if(ctr == 4)
            {
                printf(" 4:30->5:00 |");
            }
        }
    }
    printf("\b \n");
}

void print_today_reservations(void)//////////////////////////////print only reserved slots??????
{
    u32_t ctr = 0;
    printf(space"Today's Slots : \n");
    printf(space"   Slot 1   |   Slot 2   |   Slot 3   |   Slot 4   |   Slot 5   \n");
    printf(space" 2:00->2:30 | 2:30->3:00 | 3:00->3:30 | 4:00->4:30 | 4:30->5:00 \n");
    printf(space);
    for(ctr = 0; ctr < slots_num; ctr++)
    {
        if(slots[ctr] == 0)
        {
            printf("            |");
        }
        else
        {
            printf("   ID = %i   |", slots[ctr]);
        }
    }
    printf("\b \n");
}






















