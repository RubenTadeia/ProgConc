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

void sort_classroom_alphabetically(aluno* student){

	/* Testes com as o sorting
	char a = 'a';
	char b = 'b';
	printf("%c  %c\n",a , b);
	printf("%d  %d\n",a , b); 
	// Resultado
	// a   b
	// 97  98
	*/
	aluno *ptr;
	aluno n;
	n.next = student;
	for( ptr = &n; ptr; ptr = ptr->next){
		for(aluno *ptr2 = ptr->next; ptr2; ptr2 = ptr2->next){
			// Vamos comparar os dois nomes deles
			printf("%c %d\n", (char) tolower(ptr->next->name[0]), (char) tolower(ptr->next->name[0]));
			printf("%c %d\n", (char) tolower(ptr2->next->name[0]), (char) tolower(ptr2->next->name[0]));
			if( (char) tolower(ptr->next->name[0]) > (char) tolower(ptr2->next->name[0]) ){
				if(ptr->next == student){
					student = ptr2->next;
				}
				//then swap ptr and ptr2
				aluno*temp = ptr->next;
				ptr->next = ptr2->next;
				ptr2->next = temp;
			}
		}
	}
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