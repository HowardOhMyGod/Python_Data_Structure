#include <stdio.h>
#include <stdlib.h>

int *copyPtr();

int main(){
	int a = 1;
	int *newPtr;
	printf("Original %p\n", &a);
	
	&a = copyPtr();
	
	printf("New:%p", &a);
	
	
}
int * copyPtr(){
	int *newPtr;
	
	newPtr = (int *) malloc(sizeof(int));
	
	return newPtr;
}

