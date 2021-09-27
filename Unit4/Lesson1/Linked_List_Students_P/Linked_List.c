/*
 * Linked_List.c
 *
 *  Created on: 27 Sep 2021
 *      Author: hassan
 */
#include"Linked_List.h"
SStudent * PFirst_Student =NULL;
void fill_record(SStudent* Newstudent){
	char temp[40];
	DPRINTF("\nEnter The Name: ");
	gets(Newstudent->Student.name);
	DPRINTF("Enter The ID: ");
	gets(temp);
	Newstudent->Student.ID = atoi(temp);
	DPRINTF("Enter The Height: ");
	gets(temp);
	Newstudent->Student.height = atof(temp);
}

void add_student(){
	SStudent* Newstudent =NULL;
	SStudent* NavigateStudent =NULL;/*Pointer for Navigating The List*/
	/*Creating A New Node To Be Placed In The List*/
	Newstudent=(SStudent *)malloc(sizeof(SStudent));
	fill_record(Newstudent);
	/*If the List Is Empty*/
	if(PFirst_Student == NULL){
		PFirst_Student=Newstudent;
		Newstudent->PNextSStudent =NULL;
	}
	else{
		NavigateStudent=PFirst_Student;
		while(NavigateStudent->PNextSStudent != NULL){
			NavigateStudent = NavigateStudent->PNextSStudent;
		}
		NavigateStudent->PNextSStudent=Newstudent;
		Newstudent->PNextSStudent=NULL;

	}
}
void get_Nth_Student(){
	char temp[40];
	int count = 0;
	DPRINTF("\n Enter The InDex:");
	gets(temp);
	int Index = atoi(temp);
	if(PFirst_Student){
		/*Searching Using Pointers*/
		SStudent* Selected_Student =PFirst_Student;

		while((count != Index )&& Selected_Student){
			Selected_Student = Selected_Student->PNextSStudent;
			count++;
		}
		if(Selected_Student){//Condition To Make Sure The Index Is In The List
			DPRINTF("\n Record Number %d",count);
			DPRINTF("\n ID %d",Selected_Student->Student.ID);
			DPRINTF("\n Name %s ",Selected_Student->Student.name);
			DPRINTF("\n Height %f",Selected_Student->Student.height);
		}else{
			DPRINTF("\n the List Does Not Have That IndexD");
		}


	}else
		DPRINTF("\n List Is Empty");


}
void delete_student(){
	char temp[40];
	DPRINTF("\n Enter The ID:");
	gets(temp);
	int ID = atoi(temp);
	if(PFirst_Student){
		/*Searching Using Two Pointers*/
		SStudent* Selected_Student =PFirst_Student;
		SStudent* Previous_Student =PFirst_Student;
		while((Selected_Student->Student.ID != ID )&& Selected_Student){
			Previous_Student = Selected_Student;
			Selected_Student = Selected_Student->PNextSStudent;
		}
		if(Selected_Student){//Condition To Make Sure The ID Is In The List
			if(PFirst_Student==Selected_Student){//Incase its FirstStudent
				PFirst_Student =Selected_Student->PNextSStudent;
				free(Selected_Student);
			}else{
				Previous_Student->PNextSStudent =Selected_Student->PNextSStudent;
				free(Selected_Student);
			}

		}else{
			DPRINTF("\n the List Does Not Have That ID");
		}


	}else
		DPRINTF("\n List Is Empty");

}
void view_students(){
	int count =0;
	SStudent * PCurrent_Student = PFirst_Student; /*Pointer For Navigating*/
	if(!PCurrent_Student){
		DPRINTF("\n List Is Empty");
	}
	while(PCurrent_Student){
		DPRINTF("\n Record Number %d",count+1);
		DPRINTF("\n ID %d",PCurrent_Student->Student.ID);
		DPRINTF("\n Name %s ",PCurrent_Student->Student.name);
		DPRINTF("\n Height %f",PCurrent_Student->Student.height);
		count++;
		PCurrent_Student=PCurrent_Student->PNextSStudent;
	}
}
void delete_All(){
	SStudent * PCurrent_Student = PFirst_Student; /*Pointer For Navigating*/
	while(PFirst_Student){
		PCurrent_Student=PFirst_Student;
		PFirst_Student=PFirst_Student->PNextSStudent;
		free(PCurrent_Student);
	}
}
void reverse_list(){
	SStudent* PCurrent_Student =PFirst_Student;
	SStudent* Previous_Student =PFirst_Student;
	SStudent* Next_Student =PFirst_Student;
	while(PCurrent_Student){
		Next_Student=PCurrent_Student->PNextSStudent;
		PCurrent_Student->PNextSStudent=Previous_Student;
		Previous_Student=PCurrent_Student;
		PCurrent_Student=Next_Student;
	}
	PFirst_Student->PNextSStudent=NULL;
	PFirst_Student=Previous_Student;
}
