#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void traverse(struct Node *head);
void addNode(struct Node **Head, char **name, int age);
void pop(struct Node **Head);

struct Node {
	char name[20];
	int age;
	struct Node *nextNode;
};

void traverse(struct Node *head){

	while(head != NULL){
		printf("Name = %s\n", head->name);
		printf("Age = %d\n", head->age);
		printf("--------\n");

		head = head-> nextNode ;
	}
}

void addNode(struct Node **Head, char *name, int age){
	struct Node *newNode;
	
	newNode = (struct Node *) malloc(sizeof(struct Node));
	strcpy(newNode -> name, name);
	newNode -> age = age;
	free(name);
	
	if(!*Head){
		*Head = newNode;
		newNode -> nextNode = NULL;
	} else {
		newNode -> nextNode = *Head;
		*Head = newNode;
	}		
}

void pop(struct Node **Head){
	struct Node *popNode;
	
	popNode = *Head;
	*Head = (*Head)->nextNode;
	
	free(popNode);
}

int main(){
	struct Node *Head = NULL;
	
	char *name;
	int age;
	int mode;
	
	while(true){
		printf("1 : Push; 2: Pop\n");
		scanf("%d", &mode);
		
		switch(mode){
			case 1:
				printf("Add A Node.\n --------------\n");
				name = (char *) malloc(sizeof(char) * 20);
				printf("Enter Name:¡@");
				scanf("%s", name);
		//		printf("\n");
				
				printf("Enter Age:  ");
				scanf("%d", &age);
		//		printf("\n");
				
				addNode(&Head, name, age);
			
				traverse(Head);
				break;
			case 2:
				printf("Pop A Node.\n --------------\n");
				pop(&Head);
				
				traverse(Head);
				break;
		
		}
	}
} 


