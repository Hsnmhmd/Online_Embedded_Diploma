/*
 * Ex5.c
 *
 *  Created on: 14 Jun 2021
 *      Author: hassan
 */
#include<stdio.h>
#include<stdint.h>
int main(){
	char character;
	printf("Enter a char: ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&character);

	printf("Decimal Value of the Ascii %d",character);

	return 0;
}

