#include "aluno.h"

void student_insert_begining(aluno** head, char * studentName, int number){

	aluno* newStudent = (aluno*) malloc(sizeof(aluno));

	//newStudent->name = malloc(strlen(studentName)+1);
	newStudent->name = calloc(strlen(studentName)+1, sizeof(char *));
	strcpy(newStudent->name,studentName);
	newStudent->number = number;
	newStudent->next = *head;

	//changing the new head to this freshly entered node
	*head = newStudent; 
}

void student_insert_end(aluno** head, char * studentName, int number){

	aluno* newStudent = (aluno*) malloc(sizeof(aluno));

	//newStudent->name = malloc(strlen(studentName)+1);
	newStudent->name = calloc(strlen(studentName)+1, sizeof(char *));
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

// Bubble sort the given linked list
void bubbleSort(aluno *turma){
// https://www.geeksforgeeks.org/c-program-bubble-sort-linked-list/	
	int swapped;
	aluno *ptr1;
	aluno *lptr = NULL;

	int i = 0;

	//Checking for empty list
	if (turma == NULL){
		return;
	}
	
	do{
		swapped = 0;
		ptr1 = turma;

		while (ptr1->next != lptr){
			if (ptr1->next->name != NULL) {
				//Logica para ordernar por todos os caracters ao inves de apenas pelo primeiro
				if( (char) tolower(ptr1->name[0]) > (char) tolower(ptr1->next->name[0]) ){
					swap(ptr1, ptr1->next);
					swapped = 1;
				}
				else if ( (char) tolower(ptr1->name[0]) == (char) tolower(ptr1->next->name[0]) ){
					char * aux_one = calloc(strlen(ptr1->name)+1, sizeof(char *));
					char * aux_two = calloc(strlen(ptr1->next->name)+1, sizeof(char *));
					strcpy(aux_one,ptr1->name);
					strcpy(aux_two,ptr1->next->name);

					for (i = 1; i < strlen(ptr1->name); i++){
						if( (char) tolower(aux_one[i]) > (char) tolower(aux_two[i]) ){
							//printf("DEBUG: one -> %s\ntwo -> %s\n",aux_one,aux_two);
							//printf("DEBUG: one -> %c\ntwo -> %c\n",aux_one[i],aux_two[i]);
							swap(ptr1, ptr1->next);
							swapped = 1;
							//printf("\n\nSeparador\n\n");
							break;
						}
						else if( (char) tolower(aux_one[i]) < (char) tolower(aux_two[i]) ){
							break;
						}
						else if( (char) tolower(aux_one[i]) == (char) tolower(aux_two[i]) ){
							continue;
						}
					}
					free(aux_one);
					free(aux_two);
				}
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
	while (swapped);
}

//function to swap data of two nodes a and b
void swap(aluno *a, aluno *b)
{
	char * temp = calloc(strlen(a->name)+1, sizeof(char *));
	strncpy(temp,a->name,strlen(a->name)+1);
	strncpy(a->name,b->name,strlen(b->name)+1);
	strncpy(b->name,temp,strlen(temp)+1);
	free(temp);
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

void freeTurma(aluno* head)
{
	aluno * tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->name);
		free(tmp);
	}

}