#include <stdio.h>
#include <stdlib.h>

int add(int a, int b);

int add(int a, int b){
	return a + b;
}
int main(){
	int (*func)(int, int) = add;
	
	printf("%d\n", func(1,2));
}
