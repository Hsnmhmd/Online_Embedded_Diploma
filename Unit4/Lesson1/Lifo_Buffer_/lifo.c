/*
 * lifo.c
 *
 *  Created on: 25 Aug 2021
 *      Author: hassan
 */
#include"lifo.h"
LIFO_Buf_Status_t LIFO_Add_item(LIFO_Buf_t* LBUF,unsigned char item){
	/*Check lifo is valid*/
	if(!LBUF->Base || !LBUF->head)
		return LIFO_Null;
	/*Check lifo is full*/
	if(LBUF->count == LBUF->length)
		return LIFO_full;
	/*Adding*/
	LBUF->count++;
	*(LBUF->head) = item;
	LBUF->head++;
	return LIFO_no_error;
}
LIFO_Buf_Status_t LIFO_get_item(LIFO_Buf_t* LBUF,unsigned char* item){
	/*Check lifo is valid*/
	if(!LBUF->Base || !LBUF->head)
		return LIFO_Null;
	/*Check lifo is empty*/
	if(LBUF->count == 0)
		return LIFO_empty;
	LBUF->head--;
	*item =*(LBUF->head);
	LBUF->count--;
	return LIFO_no_error;
}
LIFO_Buf_Status_t LIFO_init(LIFO_Buf_t* LBUF,unsigned char* item,unsigned int length){
	if(item == NULL)
		return LIFO_Null;
	LBUF->count = 1;
	LBUF->head = item;
	LBUF->Base = item;
	LBUF->length = length;
	return LIFO_no_error;
}

