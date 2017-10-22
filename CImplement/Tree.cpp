#include <stdio.h>
#include <string.h>

struct Node {
	char data;
	struct Node *left;
	struct Node *right;
};

void preOrder(struct Node *root);
void inOrder(struct Node *root);
void postOrder(struct Node *root);

void preOrder(struct Node *root){
	if(root == NULL) return;
	printf("%c ", root -> data);
	preOrder(root -> left);
	preOrder(root -> right);
}

void inOrder(struct Node *root){
	if(root == NULL) return;
	inOrder(root -> left);
	printf("%c ", root -> data);
	inOrder(root -> right);
}

void postOrder(struct Node *root){
	if(root == NULL) return;
	
	postOrder(root->left);
	postOrder(root -> right);
	printf("%c ", root -> data);
}

int main(){
	struct Node root, ch1, ch2, s11, s12, s21, s22;
	
	root.data = 'A';
	root.left = &ch1;
	root.right = &ch2;
	
	ch1.data = 'B';
	ch1.left = &s11;
	ch1.right = &s12;
	
	ch2.data = 'C';
	ch2.left = &s21;
	ch2.right = &s22;
	
	s11.data = 'D';
	s11.left = NULL;
	s11.right = NULL;
	
	s12.data = 'E';
	s12.left = NULL;
	s12.right = NULL;
	
	s21.data = 'F';
	s21.left = NULL;
	s21.right = NULL;
	
	s22.data = 'G';
	s22.left = NULL;
	s22.right = NULL;
	
	printf("PreOrder : \n");
	preOrder(&root);
	printf("\n");
	printf("------------\n");
	printf("inOrder : \n");
	inOrder(&root);
	printf("\n");
	printf("------------\n");
	printf("postOrder : \n");
	postOrder(&root);
	printf("\n");
	printf("------------\n");
	
	
} 
