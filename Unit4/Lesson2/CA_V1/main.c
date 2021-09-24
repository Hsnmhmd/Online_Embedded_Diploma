/*
 * main.c
 *
 *  Created on: 23 Sep 2021
 *      Author: hassan
 */
#include"CA.h"

int main(){
	CA_state = STATE(CA_Waiting);
	while(1){
		CA_state();
		/*Delay*/
		for(int d=0;d<1000;d++){}
	}
	return 0;
}
