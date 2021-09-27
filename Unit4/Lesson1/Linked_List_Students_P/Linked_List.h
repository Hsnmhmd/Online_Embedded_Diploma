/*
 * Linked_List.h
 *
 *  Created on: 27 Sep 2021
 *      Author: hassan
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DPRINTF(...) {fflush(stdin);\
		fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);\
		fflush(stdout);}



typedef struct{
	int ID;
	char name[40];
	float height;
}Sdata;
typedef struct SStudent{
	Sdata Student;
	struct SStudent * PNextSStudent;
}SStudent;

/*APIs For Main Application*/
void fill_record(SStudent* Newstudent);
void add_student();
void get_Nth_Student();
void delete_student();
void view_students();
void delete_All();
void reverse_list();

#endif /* LINKED_LIST_H_ */
