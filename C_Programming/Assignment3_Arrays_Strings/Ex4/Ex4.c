/*
 * Ex4.c
 *	A Code To insert An Element In A
 *	Specific Location in An Array
 *  Created on: 23 Jun 2021
 *      Author: hassan
 *
 */
#include<stdio.h>
int main(){
	unsigned int i,j,Inserted_Num,location;
	int a[100];
	printf("Enter The Number of  The Elements\t");
	fflush(stdin);fflush(stdout);
	scanf("%d",&j);
	for (i=0;i<j;i++){
		printf("%d. Enter Number \t",i);
		fflush(stdin);fflush(stdout);
		scanf("%d",&a[i]);
	}
	printf("Enter The Number You Want To Insert\t");
	fflush(stdin);fflush(stdout);
	scanf("%d",&Inserted_Num);
	printf("Enter Its Location\t");
	fflush(stdin);fflush(stdout);
	scanf("%d",&location);
	for (i=j;i>=location;i--){
		a[i]=a[i-1];
	}
	a[location-1]=Inserted_Num;
	for (i=0;i<=j;i++){
		printf("%d\t",a[i]);

	}
	return 0;
}

