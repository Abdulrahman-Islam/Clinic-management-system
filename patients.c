#include "STD_TYP.h"
#include "patients.h"
#include<stdio.h>
#include <stdlib.h>

node_t* head = NULL; 

void add_patient(void)
{
	u32_t temp_id = 0;
	node_t* ptr_new = (node_t*)malloc(sizeof(node_t));//create new node
	printf("Please enter ID to add : ");//get id from user
	scanf(" %i", &(temp_id));
	if((!check_id_exist(temp_id)) && (temp_id > 0) && (temp_id < 10))//check if id is not repeated
	{
		ptr_new->id = temp_id;
		printf("Please enter name : ");//get information from user
		scanf(" %[^\n]s", ptr_new->name);
		printf("Please enter age : ");
		scanf(" %i", &(ptr_new->age));
		printf("Please enter gender (female:f male:m): ");
		scanf(" %c", &(ptr_new->gender));
		ptr_new->next = NULL;
		if(head == NULL)//put this node at the end of linked list
		{
			head = ptr_new;
		}
		else
		{
			node_t* ptr_loop = head;
			while(ptr_loop->next != NULL)
			{
				ptr_loop= ptr_loop->next ;
			}
			ptr_loop->next = ptr_new;
		}
		printf(space"patient added correctly\n");
	}
	else
	{
		printf(space"Invalid ID !!!\n");
	}


}

void view_patient(void)
{
	u32_t temp_id = 0;
	node_t* ptr_temp = head;
	u32_t ctr = 0;
	printf("Please enter ID to view : ");//get id from user
	scanf(" %i", &(temp_id));
	if(check_id_exist(temp_id))//check if id is exist
	{
		printf(space"-------------------------\n");

		while(ptr_temp != NULL)
		{
			if(ptr_temp->id == temp_id)
			{
				printf(space"ID     --> %i\n", ptr_temp->id);
				printf(space"Name   --> %s\n", ptr_temp->name);
				printf(space"Age    --> %i\n", ptr_temp->age);
				printf(space"gender --> %c\n", ptr_temp->gender);
				break;
			}
			ptr_temp = ptr_temp->next;
		}

		printf(space"-------------------------\n");
	}
	else
	{
		printf(space"Invalid ID !!!\n");
	}
	
}

// //not needed
// void delete_patient(void)
// {
// 	u32_t temp_id = 0;
// 	node_t* ptr_temp = head;
// 	node_t* ptr_previous = head;
// 	printf("Please enter ID to delete : ");//get id from user
// 	scanf(" %i", &(temp_id));
// 	if(check_id_exist(temp_id))//check if id is exist
// 	{
// 		while(ptr_temp != NULL)
// 		{
// 			if(ptr_temp->id == temp_id)
// 			{
// 				if(ptr_temp != head)
// 				{
// 					ptr_previous->next = ptr_temp->next;
// 					break;
// 				}
// 				else
// 				{
// 					head = ptr_temp->next;
// 					break;
// 				}
// 			}
// 			ptr_previous = ptr_temp;
// 			ptr_temp = ptr_temp->next;
// 		}
// 		printf("patient deleted correctly\n");
// 	}
// 	else
// 	{
// 		printf("Invalid ID !!!\n");
// 	}
// }

void edit_patient(void)
{
	u32_t temp_id = 0;
	u32_t value = 0;//delete it
	node_t* ptr_temp = head;
	u32_t ctr = 0;
	printf("Please enter ID to edit : ");//get id from user
	scanf(" %i", &(temp_id));
	if(check_id_exist(temp_id))//check if id is exist
	{
		while(ptr_temp != NULL)
		{
			if(ptr_temp->id == temp_id)
			{
				printf("Please enter name : ");//get information from user
				scanf(" %[^\n]s", ptr_temp->name);
				printf("Please enter age : ");
				scanf(" %i", &(ptr_temp->age));
				printf("Please enter gender (female:f male:m): ");
				scanf(" %c", &(ptr_temp->gender));
				break;
			}
			ptr_temp = ptr_temp->next;
		}
		printf(space"patient updated correctly\n");
	}
	else
	{
		printf(space"Invalid ID !!!\n");
	}
	
}

int check_id_exist(u32_t id)
{
	u32_t exist = 0;
	node_t* ptr_temp = head;
	if(ptr_temp == NULL)
	{
		exist = 0;//not exist
	}
	else
	{
		while(ptr_temp != NULL)
		{
			if(ptr_temp->id == id)
			{
				exist = 1;
				break;
			}
			ptr_temp = ptr_temp->next;
		}
	}
	return (exist);
}


















