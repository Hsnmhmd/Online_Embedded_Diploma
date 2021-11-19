/*
 * main.c
 *
 *  Created on: 7 Oct 2021
 *      Author: hassan
 */


#include"fifo.h"
//struct sinfo s[50];
void setup(){
	Students_DB_Init(15);
}


int main(){
	setup();
	char temp[40];
	while(1){
		DPRINTF("\n =============================");
		DPRINTF("\n Choose One Of The Following Options");
		DPRINTF("\n 1: Add Student Manaully");
		DPRINTF("\n 3: Delete Student Using Roll # ");
		DPRINTF("\n 4: View Student With First Name");
		DPRINTF("\n 5: Print Total Number of Students ");
		DPRINTF("\n 6: View Students in A Sepecific Course ");
		DPRINTF("\n 7: View Student With Roll Number");
		DPRINTF("\n 8: View All Students In Database");

		DPRINTF("\n Option Number: ");
		gets(temp);
		DPRINTF("\n =============================");
		switch( atoi(temp)){
		case 1:
			Add_Student_M();
			break;
		case 3:
			Delete_A_RollStudent();
			break;
		case 4:
			View_Fname_Student();
			break;
		case 5:
			Print_All();
			break;
		case 6:
			View_Students_in_Course();
			break;
		case 7:
			View_r_Student();
			break;
		case 8:
			View_Students();
			break;
		default:
			DPRINTF("\n Wrong Choise");
			break;
			////////////////
		}
	}
	return 0;
}

