#include <stdio.h>
#include "FunctionHeadersMrndTest3.h"
#include <stdlib.h>"
struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct enode{
	char data[6];
	struct enode *left;
	struct enode *right;
};

struct node_dll{
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};
struct node_dll *newNode_DLL_spec(int key)
{
	struct node_dll *temp = (struct node_dll *)malloc(sizeof(struct node_dll));
	temp->data = key;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
struct node_dll * make_dll_spec(int *arr, int len){
	struct node_dll *root = newNode_DLL_spec(arr[0]);
	struct node_dll *temp = root;
	for (int i = 1; i < len; i++){
		struct node_dll *cur = newNode_DLL_spec(arr[i]);
		temp->next = cur;
		cur->prev = temp;
		temp = temp->next;
	}
	return root;
}


struct node *newNode_spec(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * add_node_spec(struct node *root, int data){
	if (root == NULL) return newNode_spec(data);

	if (data < root->data)
		root->left = add_node_spec(root->left, data);
	else if (data > root->data)
		root->right = add_node_spec(root->right, data);

	return root;
}

void printArray(int *arr, int len){
	for (int i = 0; i < len; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void printDLL(struct node_dll *root){
	while (root != NULL){
		printf("%d ", root->data);
		root = root->next;
	}
	printf("\n");
}

void printBST(struct node * root){
	if (root != NULL){
		printBST(root->left);
		printf("%d ", root->data);
		printBST(root->right);
	}
}
int main(){
	//Test here
	struct node *root;
	struct node_dll *head;
	root = NULL;
	int arr[] = {10,5,1,7,15,12,30};
	int l = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < l; i++){
		root = add_node_spec(root, arr[i]);
	}
	head = make_dll_spec(arr, l);
	printf("%d ", is_identical(head, root));
	getchar();
	return 0;
};