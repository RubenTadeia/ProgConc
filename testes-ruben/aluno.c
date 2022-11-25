#include "aluno.h"

void student_insert_begining(aluno** head, char * studentName, int number){

	aluno* newStudent = (aluno*) malloc(sizeof(aluno));

	newStudent->name = malloc(strlen(studentName)+1);
	strcpy(newStudent->name,studentName);
	newStudent->number = number;
	newStudent->next = *head;

	//changing the new head to this freshly entered node
	*head = newStudent; 
}

void student_insert_end(aluno** head, char * studentName, int number){

	aluno* newStudent = (aluno*) malloc(sizeof(aluno));

	newStudent->name = malloc(strlen(studentName)+1);
	strcpy(newStudent->name,studentName);
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

void order_classroom_and_print(aluno* student){

	int i = 1;
	//as linked list will end when Node is Null
	while(student->next!=NULL){
		student->number = i;
		printf("Name = %s\nNumber = %d\n",student->name, student->number);
		student = student->next;
		i++;
	}
	printf("\n");
}

void print_class(aluno* student){

	//as linked list will end when Node is Null
	while(student->next!=NULL){
		printf("Name = %s\nNumber = %d\n",student->name, student->number);
		student = student->next;
	}
	printf("\n");
}

void print_class_with_null(aluno* student){

	//as linked list will end when Node is Null
	while(student!=NULL){
		printf("Name = %s\nNumber = %d\n",student->name, student->number);
		student = student->next;
	}
	printf("\n");
}