/*
 * Ex1_Strings.c
 *	N# of Occurance of aChar In a String
 *  Created on: 23 Jun 2021
 *      Author: hassan
 */
#include<stdio.h>
int main(){
	unsigned int i,N=0;
	char a[100],j;
	printf("Enter The String\t");
	fflush(stdin);fflush(stdout);
	gets(a);
	printf("Enter the char \t");
	fflush(stdin);fflush(stdout);
	scanf("%c",&j);
	for (i=0;a[i]!=0;i++){
		if(a[i]==j)
			N++;
	}
	printf("Number of Occurance is %d\t",N);
	return 0;
}

