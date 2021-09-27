/*
 * main.c
 *
 *  Created on: 31 Aug 2021
 *      Author: hassan
 */

#include"fifo.h"
#define width1 5
element_type uart_buff[width1];
int main(){
	FIFO_Buf_t FIFO_UART;
	element_type i ,temp;
	if(FIFO_init(&FIFO_UART, uart_buff, 5) == FIFO_no_error)
		printf("fifo init ____DONE\n");
	for(i=0;i<7;i++){
		printf("FIFO ENqueue (%x) \n",i);
		if(FIFO_enqueue(&FIFO_UART,i)==FIFO_no_error)
			printf("fifo enqueue ____DONE\n");
		else
			printf("fifo Enqueue ____Failed\n");
	}
	FIFO_print(&FIFO_UART);
	if(FIFO_dequeue(&FIFO_UART,&temp)==FIFO_no_error)
		printf("fifo dequeue %x ____DONE\n",temp);
	if(FIFO_dequeue(&FIFO_UART,&temp)==FIFO_no_error)
		printf("fifo dequeue %x	____DONE\n",temp);
	FIFO_print(&FIFO_UART);
	return 0;
}

