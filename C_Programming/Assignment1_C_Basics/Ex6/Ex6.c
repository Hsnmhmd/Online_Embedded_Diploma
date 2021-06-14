/*
 * Ex6.c
 *
 *  Created on: 14 Jun 2021
 *      Author: hassan
 */
#include<stdio.h>
#include<stdint.h>
int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	float a,b;
	printf("Enter two value of a , b in order : ");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&a,&b);
	b=b+a;
	a=b-a;
	b=b-a;
	fflush(stdin);
	printf("value of a: %f\n",a);
	//fflush(stdin);fflush(stdout);
	printf("value of b: %f\n",b);

	return 0;
}

