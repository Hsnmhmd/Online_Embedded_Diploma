/*
 * Students_Queue.c
 *
 *  Created on: 31 Aug 2021
 *      Author: hassan
 */
#include"fifo.h"
Ssinfo s[15];
FIFO_Buf_t Students_DB;
FIFO_Buf_t *Students_Queue=&Students_DB;
void Students_DB_Init(unsigned int length){

	Students_Queue->base = s;
	Students_Queue->head = s;
	Students_Queue->tail = s;
	Students_Queue->length = length;
	Students_Queue->count = 0;

}
void Add_Student_M(){

	char temp[40];
	DPRINTF("\nEnter The Roll No: ");
	gets(temp);
	int flag=0;
	int i =atoi(temp);
	struct sinfo* search=Students_Queue->base;
	while(search != Students_Queue->head){
		if(search->roll != i){
			search++;
		}else {
			flag =1;
			DPRINTF("\nThe Roll Number Already Exist ");
		}
	}
	//Unique Roll Number O r An empty Database
	if(flag == 0 ){
		Students_Queue->head->roll = atoi(temp);
		DPRINTF("Enter The First Name: ");
		gets(Students_Queue->head->fname);
		DPRINTF("Enter The Second Name: ");
		gets(Students_Queue->head->lname);

		DPRINTF("Enter The GPA: ");
		gets(temp);
		Students_Queue->head->GPA = atof(temp);
		DPRINTF("Enter The IDs Of Registered Courses: ");
		DPRINTF("\nEnter ID of Course 1: ");
		gets(temp);
		Students_Queue->head->cid[0] = atoi(temp);
		DPRINTF("Enter ID of Course 2: ");
		gets(temp);
		Students_Queue->head->cid[1] = atoi(temp);
		DPRINTF("Enter ID of Course 3: ");
		gets(temp);
		Students_Queue->head->cid[2] = atoi(temp);
		DPRINTF("Enter ID of Course 4: ");
		gets(temp);
		Students_Queue->head->cid[3] = atoi(temp);
		DPRINTF("Enter ID of Course 5: ");
		gets(temp);
		Students_Queue->head->cid[4] = atoi(temp);

		Students_Queue->count++;

		if(Students_Queue->head == (Students_Queue->base + Students_Queue->length * sizeof(struct sinfo)))
			Students_Queue->head = Students_Queue->base;
		else
			Students_Queue->head++;
		DPRINTF("\n[INFO] Student Details Are Added Successfully ");
		DPRINTF("\n[INFO] Students Number IS %d ",Students_Queue->count);
	}
}
void View_r_Student(){
	char temp[40];
	int flag = 0;
	DPRINTF("\n Enter Roll #:");
	gets(temp);
	int Index = atoi(temp);
	struct sinfo* search=Students_Queue->base;
	while(search != Students_Queue->head){
		if(search->roll != Index){
			search++;
		}else {
			flag =1;
			DPRINTF("\nFirst Name: %s ",search->fname);
			DPRINTF("\nLast Name: %s ",search->lname  );
			DPRINTF("\nRoll Num: %d ",search->roll);
			DPRINTF("\nGPA: %f",search->GPA);
			DPRINTF("\nCourse 1 ID: %d ",search->cid[0]);
			DPRINTF("\nCourse 2 ID: %d ",search->cid[1]);
			DPRINTF("\nCourse 3 ID: %d ",search->cid[2]);
			DPRINTF("\nCourse 4 ID: %d ",search->cid[3]);
			DPRINTF("\nCourse 5 ID: %d ",search->cid[4]);
			//Stop Search There Is Only One Roll
			//To Not Stuck In A Infinite loop
			break;
		}
	}
	//List Is Empty or Roll Number Does not Exist
	if(flag == 0){
		DPRINTF("\n[ERROR] List Is Empty or Roll Number Does not Exist");
	}



}
void View_Students(){
	int flag = 0;
	struct sinfo* search=Students_Queue->base;
	while(search != Students_Queue->head){

		flag =1;
		DPRINTF("\nFirst Name: %s ",search->fname);
		DPRINTF("\nLast Name: %s ",search->lname  );
		DPRINTF("\nRoll Num: %d ",search->roll);
		DPRINTF("\nGPA: %f",search->GPA);
		DPRINTF("\nCourse 1 ID: %d ",search->cid[0]);
		DPRINTF("\nCourse 2 ID: %d ",search->cid[1]);
		DPRINTF("\nCourse 3 ID: %d ",search->cid[2]);
		DPRINTF("\nCourse 4 ID: %d ",search->cid[3]);
		DPRINTF("\nCourse 5 ID: %d ",search->cid[4]);
		search++;


	}
	//List Is Empty or Roll Number Does not Exist
	if(flag == 0){
		DPRINTF("\n[ERROR] List Is Empty or Roll Number Does not Exist");
	}


}
void View_Fname_Student(){
	char temp[50];
	int flag = 0;
	DPRINTF("\n Enter First Name :");
	gets(temp);
	struct sinfo* search=Students_Queue->base;
	while(search != Students_Queue->head){
		if(stricmp(search->fname, temp)){
			search++;
		}else {
			flag =1;
			DPRINTF("\nFirst Name: %s ",search->fname);
			DPRINTF("\nLast Name: %s ",search->lname  );
			DPRINTF("\nRoll Num: %d ",search->roll);
			DPRINTF("\nGPA: %f",search->GPA);
			DPRINTF("\nCourse 1 ID: %d ",search->cid[0]);
			DPRINTF("\nCourse 2 ID: %d ",search->cid[1]);
			DPRINTF("\nCourse 3 ID: %d ",search->cid[2]);
			DPRINTF("\nCourse 4 ID: %d ",search->cid[3]);
			DPRINTF("\nCourse 5 ID: %d ",search->cid[4]);
			//To Complete Search For Any Student With Same Fname
			//And Not To Stuck In An Infinite loop
			search++;
		}
	}
	//List Is Empty or Roll Number Does not Exist
	if(flag == 0){
		DPRINTF("\n[ERROR] List Is Empty or First Name Does not Exist");
	}
}
void View_Students_in_Course(){
	char temp[40];
	int flag = 0;
	DPRINTF("\n Enter Course ID #:");
	gets(temp);
	int Index = atoi(temp);
	struct sinfo* search=Students_Queue->base;
	while(search != Students_Queue->head){
		for(int i=0;i<5;){
			if(search->cid[i] != Index){
				i++;
			}else {
				flag =1;
				DPRINTF("\nFirst Name: %s ",search->fname);
				DPRINTF("\nLast Name: %s: ",search->lname  );
				DPRINTF("\nRoll Num: %d ",search->roll);
				DPRINTF("\nGPA: %f",search->GPA);
				DPRINTF("\nCourse 1 ID: %d ",search->cid[0]);
				DPRINTF("\nCourse 2 ID: %d ",search->cid[1]);
				DPRINTF("\nCourse 3 ID: %d ",search->cid[2]);
				DPRINTF("\nCourse 4 ID: %d ",search->cid[3]);
				DPRINTF("\nCourse 5 ID: %d ",search->cid[4]);
				//Stop Search Student Can Be Registerd in Course Once
				//To Not Stuck In A Infinite loop
				//Break The Inner Loop To Continue Search For Other Students
				break;
			}
		}search++;
	}
	//List Is Empty or No Registered Students In That Course
	if(flag == 0){
		DPRINTF("\n[ERROR] List Is Empty or No Registered Students In That Course");
	}



}
void Print_All(){
	DPRINTF("\n[INFO] Students Number IS %d ",Students_Queue->count);
}
void Delete_A_RollStudent(){
	char temp[40];
	int flag = 0;
	DPRINTF("\n Enter Roll #:");
	gets(temp);
	int Index = atoi(temp);
	struct sinfo* search=Students_Queue->base;
	while(search != Students_Queue->head){
		if(search->roll != Index){
			search++;
		}else {
			flag =1;
			//Move elements AFTER REMOVED ELEMNT
			while(search != Students_Queue->head){
				search->GPA=(search+1)->GPA;
				search->roll=(search+1)->roll;
				strcpy(search->fname,(search+1)->fname);
				strcpy(search->lname,(search+1)->lname);
				//search->fname=(search+1)->fname;
				//search->lname=(search+1)->lname;
				search->cid[0]=(search+1)->cid[0];
				search->cid[1]=(search+1)->cid[1];
				search->cid[2]=(search+1)->cid[2];
				search->cid[3]=(search+1)->cid[3];
				search->cid[4]=(search+1)->cid[4];
				search++;
			}
			//Move The Head
			Students_Queue->head=(--search);
			Students_Queue->count--;
			//Stop Search There Is Only One Roll
			//To Not Stuck In A Infinite loop
			break;
		}
	}
	//List Is Empty or Roll Number Does not Exist
	if(flag == 0){
		DPRINTF("\n[ERROR] List Is Empty or Roll Number Does not Exist");
	}



}

