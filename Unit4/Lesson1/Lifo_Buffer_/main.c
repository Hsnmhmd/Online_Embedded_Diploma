/*
 * main.c
 *
 *  Created on: 21 Sep 2021
 *      Author: hassan
 */
#include"lifo.h"
int main(){
	unsigned char Staticbuffer[LIFO_Buf_Length];
	unsigned char i,temp;
	LIFO_Buf_t first_buffer, second_buffer;
	//Initialize Using Dynamic Allocation
	first_buffer.Base=(unsigned char*)malloc(LIFO_Buf_Length);
	if(!first_buffer.Base){}
	//setting length of buffer
	first_buffer.length=5;
	//setting head pointer
	first_buffer.head=first_buffer.Base;
	//setting count
	first_buffer.count=0;
	printf("\n First Buffer (Dynamic Allocation) LIFO_push_item =");
	for(i=0;i<5;i++){
		printf("%d",i);
		LIFO_Add_item(&first_buffer, i);
	}
	printf("\n First Buffer (Dynamic Allocation) LIFO_pop_item =");
	for(i=0;i<5;i++){
		LIFO_get_item(&first_buffer, &temp);
		printf("%d",temp);
	}
	//Initialize Using Static Allocation
	second_buffer.Base=&Staticbuffer[0];

	//setting length of buffer
	second_buffer.length=5;
	//setting head pointer
	second_buffer.head=first_buffer.Base;
	//setting count
	second_buffer.count=0;
	printf("\n second Buffer (Static Allocation) LIFO_push_item =");
	for(i=0;i<5;i++){
		printf("%d",i);
		LIFO_Add_item(&second_buffer, i);
	}
	printf("\n Second Buffer (Static Allocation) LIFO_push_item =");
	for(i=0;i<5;i++){
		LIFO_get_item(&second_buffer, &temp);
		printf("%d",temp);
	}
	return 0;
}

