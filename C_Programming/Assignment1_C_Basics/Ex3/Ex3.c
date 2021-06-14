/*
 * Ex3.c
 *
 *  Created on: 14 Jun 2021
 *      Author: hassan
 */
#include<stdio.h>
#include<stdint.h>
int main(){
	int int1,int2;
	int sum;
	printf("Enter two integers: ");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&int1,&int2);
	//fflush(stdin);fflush(stdout);
	sum=int1+int2;
	printf("sum: %d",sum);

	return 0;
}

