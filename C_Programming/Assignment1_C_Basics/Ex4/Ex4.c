/*
 * Ex4.c
 *
 *  Created on: 14 Jun 2021
 *      Author: hassan
 */
#include<stdio.h>
#include<stdint.h>
int main(){
	float int1,int2;
	float Product;
	printf("Enter two NUMS: ");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&int1,&int2);
	//fflush(stdin);fflush(stdout);
	Product=int1*int2;
	printf("sum: %f",Product);

	return 0;
}

