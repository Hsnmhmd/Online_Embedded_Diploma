/*
 * Ex3S.c
 *
 *  Created on: 23 Jun 2021
 *      Author: hassan
 */
#include<stdio.h>
#include<string.h>
int main(){
	unsigned int i,j=0,n=0;
	char a[100],temp;
	printf("Enter The String\t");
	fflush(stdin);fflush(stdout);
	gets(a);
	//n=strlen(a)-1;
	for (i=0;a[i]!='\0';i++)
		n++;
	n--;
/*	for(j=0;j<i;j++,i--){
		temp=a[j];
		a[j]=a[i];
		a[i]=temp;
	}*/
	while(j<n){
		temp=a[j];
		a[j]=a[n];
		a[n]=temp;
		n--;
		j++;
	}
	printf("Reversed String is %s\t",a);
	return 0;
}

