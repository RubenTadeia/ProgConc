#include "aluno.h"

void student_insert_begining(aluno** head, char * studentName, int number){

	aluno* newStudent = (aluno*) malloc(sizeof(aluno));

	newStudent->name = studentName;
	newStudent->number = number;
	newStudent->next = *head;

	//changing the new head to this freshly entered node
	*head = newStudent; 
}

void student_insert_end(aluno** head, char * studentName, int number){

	aluno* newStudent = (aluno*) malloc(sizeof(aluno));

	newStudent->name = studentName;
	newStudent->number = number;
	newStudent->next = NULL;

	//need this if there is no node present in linked list at all
	if(*head==NULL){
		*head = newStudent;
		return;
	}

	aluno * temp = *head;

	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = newStudent;
}

void print_class(aluno* student){

	//as linked list will end when Node is Null
	//while(student->next!=NULL){
	while(student!=NULL){
		printf("Name = %s\nNumber = %d\n",student->name, student->number);
		student = student->next;
	}
	printf("\n");
}