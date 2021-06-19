/*
 * Ex1.c
 *
 *  Created on: 19 Jun 2021
 *      Author: hassan
 */

#include<stdio.h>
int main(){
	unsigned int i,j;
	unsigned int a[2][2],b[2][2],sum[2][2];
	printf("Enter The Elements of the two matrices \n");
	for (i=0;i<2;i++){
		for (j=0;j<2;j++){
			printf("Enter The Element a[%d][%d] in The 1st Array\t",i,j);
			fflush(stdin);fflush(stdout);
			scanf("%d",&a[i][j]);
			printf("Enter The Element b[%d][%d] in The 2nd Array\t",i,j);
			fflush(stdin);fflush(stdout);
			scanf("%d",&b[i][j]);
			sum[i][j]=a[i][j]+b[i][j];
			}printf("\n");
	}
	printf("The Sum Matrix\n");
	for (i=0;i<2;i++){
		for (j=0;j<2;j++){
			printf("%d \t",sum[i][j]);
		}printf("\n");
	}
	return 0;
}

