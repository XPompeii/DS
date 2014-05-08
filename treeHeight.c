#include <stdio.h>

struct node{
	struct node *left;
	char data;
	struct node *right;
};

int treeHeight(struct node *head){
	
	if(head==NULL){
		return;
	}else if(treeHeight(head->left)>=treeHeight(head->right)){
		return treeHeight(head->left)+1;
	}else{
		return treeHeight(head->right)+1;
	}
	

}

int main(void){
	struct node *head=NULL,A={NULL,'A',NULL},B={NULL,'B',NULL},C={NULL,'C',NULL},D={NULL,'D',NULL},E={NULL,'E',NULL},F={NULL,'F',NULL};
	
	head=&A;
	A.left=&B; A.right=&C;
	B.left=&D; B.right=&E;
	C.left=&F;
	
		
	printf("the tree height is %d\n",treeHeight(head));
	
	
	
}
