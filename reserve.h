#ifndef _RESERVE_H_
#define _RESERVE_H_

#include "STD_TYP.h"

#define slots_num 5
#define ok_sign 251
#define not_ok_sign 120  //try 88 for small X
#define space "                                                                "



void reserve_slot(void);
void cancel_reserve(void);
int check_slot_reserved(u32_t slot);
void print_avaliable_slots(void);
void print_today_reservations(void);




#endif