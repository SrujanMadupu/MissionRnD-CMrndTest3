/*

Given two Binary Search Trees ,Merge Both of them into a Single Binary Search Tree .
The Resultant Binary Search Tree will be BST1 .ie Merge all elements of BST2 into BST1.

Example 1:
Input : 
   20        25
  /  \      /  \
 5    30   10   35
Output :
Bst 1 :
     20
   /   \
  5     30
   \   /  \
   10 25   35

BST 2 can be merged in BST1 sometimes in many number of ways ,Any 1 of those correct ways would be fine .
Finally All elements of Both Trees should be in BST 1 .Dont process NULL Inputs 
(Both r1 and r2 shouldnt be NULL at the time of Input)

Note : Dont Create Nodes using malloc,or Swap the data values or else your solution would receive 100%
cut in the marks you got for this question .
You need to solve this question only by changing links.

You will also receive Bonus marks for any better optimizations you make .
Difficulty : Medium -Hard 
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node* add_node(int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->left = NULL;
	temp->data = data;
	temp->right = NULL;
	return temp;
}
void find_location(struct node *r1, int data){
	  if (data < r1->data){
		  if (r1->left == NULL){
			  r1->left = add_node(data);
			  return;
		  }
		find_location(r1->left, data);
	}
	else if (data > r1->data){
		if (r1->right == NULL){
			r1->right = add_node(data);
			return;
		}
		find_location(r1->right, data);
	}
}

void inorder_travelser(struct node *r2, struct node *r1){
	if (!r2){
		return;
	}
	inorder_travelser(r2->left, r1);
    find_location(r1, r2->data);
	inorder_travelser(r2->right, r1);
}
void merge_two_bst(struct node *root1, struct node *root2){
	inorder_travelser(root2, root1);
}