/*
 * Ex3.c
 *
 *  Created on: 19 Jun 2021
 *      Author: hassan
 */
#include<stdio.h>
int main(){
	int r,c,i,j;
	int a[10][10],atrans[10][10];
	printf("Enter The N of Raws and Columns in Order <10\t");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&r,&c);
	for (i=0;i<r;i++){
		for (j=0;j<c;j++){
			printf("Enter The Element a[%d][%d] in The Array\t",i,j);
			fflush(stdin);fflush(stdout);
			scanf("%d",&a[i][j]);
			}
	}
	printf("The The Entered Matrix\n");
	for (i=0;i<r;i++){
		for (j=0;j<c;j++){
			printf("%d \t",a[i][j]);
		}printf("\n");
	}
	for (i=0;i<r;i++){
		for (j=0;j<c;j++){
			atrans[j][i]=a[i][j];
		}
	}
	printf("The The Transposed Matrix\n");
	for (i=0;i<c;i++){
		for (j=0;j<r;j++){
			printf("%d \t",atrans[i][j]);
		}printf("\n");
	}
	return 0;
}

