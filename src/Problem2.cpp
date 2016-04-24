/*
Given a Sorted Doubly Linked List and a Binary Search Tree , Check if they are identical or not .
The DLL will have nodes of type node_dll
Note :
A DLL can be represented as a BST in many forms ,And if a dll and any one of the forms is given as input you
need to return 1 otherwise 0. 

->Dont Create an Extra Array ,or else your solution would receive 20% Cut in the Marks you got .

Examples :

Example 0:
DLL:1->5->8
BST(All 3 return 1):
    5         8      1
   / \       /        \
  1   8     5          5
           /            \
          1              8
Returns 1
    8
   / \
  5   1
Returns 0
Example 1:
DLL : 1->5
BST : 
5
 \
 10
Returns 0

Example 2:
DLL:1->3->5-9->11
BST:
    5
   / \
  1   11
   \  /      
    3 9

Returns 1

Example 3:
DLL: 1->5->7->10->12->15->20
BST:
        10
        /\
       5  15
      /\  / \
     1  7 12 20
Returns 1

Note 2 :
Unequal Length BST and DLL should return 0;
Return -1 for NULL inputs

Difficulty : Medium +
*/
#include <stdlib.h>
#include <stdio.h>

struct node_dll{
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};
struct node{
	int data;
	struct node *left;
	struct node *right;
};
int Total_nodes(struct node *root){
	if (root != NULL){
		return 1 + Total_nodes(root->left) + Total_nodes(root->right);
	}
	else{
		return 0;
	}
}
int find_length(struct node_dll *head){
	int l = 0;
	while (head->next != NULL){
		l++;
		head = head->next;
	}
	return l;
}
int EqualorNot(struct node_dll *head, struct node *root, int i, int j){
	int mid = (i + j) / 2;
	while (mid >= 0){
		head = head->next;
		mid = mid - 1;
	}
	if (root->data == head->data){
		return 1;
	}
	return 0;
}
int is_identical_Util(struct node_dll *head, struct node *root,int start,int end){
	if (!root){
		return 1;
	}
	int en = (start + end) / 2;
	if (EqualorNot(head, root, start, end) && is_identical_Util(head, root->left, start, en) && is_identical_Util(head, root->right, (start+en)/2, en)){
		return 1;
	}
	else{
		return 0;
	}
   
}
int inorderrecursion(struct node *root, int *arr, int i){
	if (root != NULL){
		i = inorderrecursion(root->left, arr, i);
		arr[i++] = root->data;
		i = inorderrecursion(root->right, arr, i);
		return i;
	}
	else{
		return i;
	}
}
int check(struct node_dll *head, int *temp){
	int i = 0;
	while (head != NULL){
		if (temp[i] != head->data){
			return 0;
		}
		i++;
		head = head->next;
	}
	return 1;
}
int is_identical(struct node_dll *head, struct node *root){
	if (!root || !head){
		return -1;
	}
	//int len = find_length(head);
	//int mid = len / 2;
	//return is_identical_Util(head, root,0,len);

	int N = Total_nodes(root);
	int *temp = (int*)malloc(sizeof(int)*N);
	
	int j = inorderrecursion(root, temp, 0);
	for (int i = 0; i < N; i++){
		printf("%d ", temp[i]);
	}
	return check(head, temp);

}