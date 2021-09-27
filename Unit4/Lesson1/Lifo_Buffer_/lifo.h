/*
 * lifo.h
 *
 *  Created on: 25 Aug 2021
 *      Author: hassan
 */

#ifndef LIFO_H_
#define LIFO_H_
#include<stdio.h>
#include<stdlib.h>
#define LIFO_Buf_Length 5
typedef struct {
	unsigned int length;
	unsigned char* Base;
	unsigned char* head;
	unsigned int count;
}LIFO_Buf_t;
typedef enum{
	LIFO_no_error,
	LIFO_full,
	LIFO_not_full,
	LIFO_empty,
	LIFO_not_empty,
	LIFO_Null,
}LIFO_Buf_Status_t;

LIFO_Buf_Status_t LIFO_Add_item(LIFO_Buf_t* LBUF,unsigned char item);
LIFO_Buf_Status_t LIFO_get_item(LIFO_Buf_t* LBUF,unsigned char* item);
LIFO_Buf_Status_t LIFO_init(LIFO_Buf_t* LBUF,unsigned char* item,unsigned int length);
#endif /* LIFO_H_ */
