/*
 * fifo.h
 *
 *  Created on: 31 Aug 2021
 *      Author: hassan
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "stdio.h"
#include "stdint.h"
#include<string.h>
#include<stdlib.h>
#define DPRINTF(...) {fflush(stdin);\
		fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);\
		fflush(stdout);}
/*User Configuration*/
/*Select Element Width or TYPE (uint8_t,uint16_t,uint32_t)*/
#define element_type uint8_t
typedef struct sinfo{
	char fname[10];
	char lname[10];
	int roll;
	float GPA;
	int cid[5];

}Ssinfo;
/* Create Buffer*/
//extern Ssinfo s[15];
/*FIFO data types*/
typedef struct{
	unsigned int length;
	unsigned int count;
	struct sinfo* base;
	struct sinfo* head;
	struct sinfo* tail;
}FIFO_Buf_t;

/*FIFO APIs*/
int Add_Students_fromFile(FILE    *textfile);
void Students_DB_Init(unsigned int length);
void Add_Student_M();
void View_r_Student();
void View_Fname_Student();
void View_Students_in_Course();
void Print_All();
void Delete_A_RollStudent();
void View_Students();

#endif /* FIFO_H_ */
