/*
 * Ex2.c
 *
 *  Created on: 19 Jun 2021
 *      Author: hassan
 */
#include<stdio.h>
int main(){
	unsigned int i,j;
	float a[100]; float sum=0;
	printf("Enter The Number of  The Elements\t");
	fflush(stdin);fflush(stdout);
	scanf("%d",&j);
	for (i=0;i<j;i++){
		printf("1. Enter Number \t");
		fflush(stdin);fflush(stdout);
		scanf("%f",&a[i]);
	}
	for (i=0;i<j;i++){
		sum+=a[i];
	}
	printf("Average is %f",sum/j);
	return 0;
}
