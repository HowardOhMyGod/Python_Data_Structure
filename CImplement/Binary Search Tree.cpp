#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BstNode {
	char name[20];
	int age;
	BstNode *left;
	BstNode *right;
} BstNode;

int max(int a, int b);
int max(int a, int b){
	if (a > b) return a;
	else return b;
}

void insert(BstNode **root, char *name, int age);
bool isBst(BstNode *root);

BstNode * newNode(char *name, int age);

BstNode * search(BstNode *root, char *name, int age);
BstNode * findMin(BstNode *root);
BstNode * findMax(BstNode *root);

BstNode * deleteNode(BstNode * root, int age);
BstNode * getSuccessor(BstNode *root, int age); 

void preOrderTraverse(BstNode *root);

int findHeight(BstNode *root);


void insert(BstNode **root, char *name, int age){
	// if root is empty
	if(*root == NULL){
		*root = newNode(name, age);
	} else if (age <= (*root)-> age){
		insert(&((*root) -> left), name, age);
	} else {
		insert(&((*root) -> right), name, age);
	}
}

BstNode * newNode(char *name, int age){
	BstNode *newNode;
	
	newNode = (BstNode *) malloc(sizeof(BstNode));
	
	strcpy(newNode -> name, name);
	newNode -> age = age;
	newNode -> right = NULL;
	newNode -> left = NULL;
	
	return newNode;
}

BstNode * findMin(BstNode *root){
	if(root == NULL) return NULL;
	else if(root -> left == NULL) return root;
	
	else findMin(root -> left);
}

BstNode * deleteNode(BstNode * root, int age){
	if(root == NULL) return root;
	
	if(age > root -> age) root -> right = deleteNode(root -> right, age);
	else if (age < root -> age) root -> left = deleteNode(root -> left, age);
	// find the node
	else {
		
		//has no child
		if(root -> right == NULL && root -> left == NULL){
			free(root);
			root = NULL;
			return root;
			
		// has one child	
		} else if (root -> right == NULL){
			BstNode *temp = root;
			root = root -> left;
			free(temp);
			return root;
			
		} else if (root -> left == NULL){
			BstNode *temp = root;
			root = root -> right;
			free(temp);
			return root;
			
		// has two childs
		} else {
			BstNode *temp = findMin(root -> right);
			root -> age = temp -> age;
			strcpy(root -> name, temp -> name);
			root -> right = deleteNode(root -> right, temp -> age);
			
		}
	}
}

BstNode * getSuccessor(BstNode *root,char *name, int age){
	BstNode *current = search(root, name, age);
	
	// if has right subtree
	if(current -> right != NULL){
		return findMin(current -> right);
	}
	// if no right subtree
	else {
		BstNode *ancestor = root;
		BstNode *succesor = NULL;
		
		// find the nearest parent for which given node in the left subtree
		while(ancestor != current){
			if(current -> age < ancestor -> age){
				succesor = ancestor;
				ancestor = ancestor -> left;
			} else {
				ancestor = ancestor -> right;
			}
		}
		
		return succesor;
	}
}

BstNode * findMax(BstNode *root){
	if(root == NULL) return NULL;
	else if(root -> right == NULL) return root;
	
	else findMin(root -> right);
}

BstNode * search(BstNode *root, char *name, int age){
	if(root == NULL) return root;
	if(strcmp(root -> name, name) == 0 && (root -> age == age)) return root;
	
	if(age <= root -> age){
		search(root -> left, name, age);
	} else {
		search(root -> right, name, age);
	}
}

// check this tree is a binary search tree
bool isBst(BstNode *root, int min, int max){
	if(root == NULL) return true;
	
	if(root-> age > min && root -> age < max
		&& isBst(root -> left, min, root -> age)
		&& isBst(root -> right, root -> age, max)){
			return true;
		}
	else return false;
}

int findHeight(BstNode *root){
	int leftHeight;
	int rightHeight;
	 
	if(root == NULL) return -1;
	
	rightHeight = findHeight(root -> right);
	leftHeight = findHeight(root -> left);
	
	return max(rightHeight, leftHeight) + 1;
}

void preOrderTraverse(BstNode *root){
	if(root == NULL) return;
	
	printf("Name: %s\n", root -> name);
	printf("Age: %d\n", root -> age);
	printf("-----------------\n");
	preOrderTraverse(root -> left);
	preOrderTraverse(root -> right);
}

int main () {
	BstNode *root = NULL;
	BstNode *minNode = NULL;
	char name[20];
	int age;
	
	insert(&root, "Howard", 20);
	insert(&root, "Anna", 22);
	insert(&root, "Candy", 10);
	insert(&root, "Mom", 50);
	insert(&root, "Dad", 30);
	insert(&root, "Daddy", 60);
	insert(&root, "Twentyone", 21);
//	preOrderTraverse(root);
	
//	printf("\n\n");
	
//	deleteNode(root, 20);
//	preOrderTraverse(root);
		
	while(1){
		printf("Enter Name: ");
		scanf("%s", name);
		printf("Enter age: ");
		scanf("%d", &age);
		
		BstNode *succesor = getSuccessor(root, name, age); 
		printf("Name: %s\n", succesor -> name);
		printf("Age: %d\n", succesor -> age);
//		
//		if(search(root, name, age)){
//			printf("Found!\n");
//		} else {
//			printf("Not Found!\n");
//		}
//		
//		if(minNode = findMin(root)){
//			printf("Min name: %s, age: %d\n", minNode -> name, minNode -> age);
//		} else printf("Root is empty!\n");
//		
//		
//		if(minNode = findMax(root)){
//			printf("Max name: %s, age: %d\n", minNode -> name, minNode -> age);
//		} else printf("Root is empty!\n");
//		
//		printf("The height of tree: %d\n", findHeight(root));
//		if(isBst(root, INT_MIN, INT_MAX)) printf("It's a BST!\n'");
//		else printf("It's not a BST\n");
		
	}
	
	return 0;
}


