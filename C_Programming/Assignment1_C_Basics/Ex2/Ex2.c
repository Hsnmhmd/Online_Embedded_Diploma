/*
 * Ex2.c
 *
 *  Created on: 14 Jun 2021
 *      Author: hassan
 */
#include<stdio.h>
#include<stdint.h>
int main(){
	uint32_t Entered_int;
	printf("Enter a integer: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&Entered_int);
	fflush(stdin);fflush(stdout);
	printf("You entered: %d",Entered_int);

	return 0;
}

