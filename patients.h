#ifndef _PATIENTS_H_
#define _PATIENTS_H_

#include "STD_TYP.h"

#define name_length 50
#define space "                                                                "


typedef struct Node{
    u32_t id;
    u8_t name[name_length];
    u32_t age;
    u8_t gender;//male: m        female: f
    struct Node* next;
}node_t;

void add_patient(void);

void view_patient(void);

//not needed
// void delete_patient(void);

void edit_patient(void);

int check_id_exist(u32_t id);

void get_name(node_t* ptr_new);

#endif




