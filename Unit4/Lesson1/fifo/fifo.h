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
/*User Configuration*/
/*Select Element Width or TYPE (uint8_t,uint16_t,uint32_t)*/
#define element_type uint8_t
/* Create Buffer*/

/*FIFO data types*/
typedef struct{
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_Buf_t;
typedef enum{
	FIFO_no_error,
	FIFO_full,
	FIFO_not_full,
	FIFO_empty,
	FIFO_not_empty,
	FIFO_Null,
}FIFO_Buf_Status_t;
/*FIFO APIs*/
FIFO_Buf_Status_t FIFO_init(FIFO_Buf_t* fifo,element_type* buf,unsigned int length);
FIFO_Buf_Status_t FIFO_enqueue(FIFO_Buf_t* fifo,element_type item);
FIFO_Buf_Status_t FIFO_dequeue(FIFO_Buf_t* fifo,element_type* item);
FIFO_Buf_Status_t FIFO_is_full(FIFO_Buf_t* fifo);
void FIFO_print(FIFO_Buf_t* fifo);
#endif /* FIFO_H_ */
