/*
 * main.c
 *
 *  Created on: 23 Sep 2021
 *      Author: hassan
 */
#include"Linked_List.h"

int main(){
	char temp[40];
	while(1){
		DPRINTF("\n =============================");
		DPRINTF("\n Choose One Of The Following Options");
		DPRINTF("\n 1: Add Student ");
		DPRINTF("\n 2: Delete Student Using ID");
		DPRINTF("\n 3: View Students");
		DPRINTF("\n 4: Delete All ");
		DPRINTF("\n 5: View Student With Nth Record Through Index");
		DPRINTF("\n 6: Reverse List ");
		DPRINTF("\n Option Number: ");
		gets(temp);
		DPRINTF("\n =============================");
		switch( atoi(temp)){
		case 1:
			add_student();
			break;
		case 2:
			delete_student();
			break;
		case 3:
			view_students();
			break;
		case 4:
			delete_All();
			break;
		case 5:
			get_Nth_Student();
			break;
		case 6:
			reverse_list();
			break;
		default:
			DPRINTF("\n Wrong Choise");
			break;
			////////////////
		}
	}
	return 0;
}
