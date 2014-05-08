#include <stdio.h>

struct node{
	struct node *left;
	char data;
	struct node *right;
};

int nodeNumber(struct node *head){
	
	if(head==NULL){
		return;
	}else if((head->left==NULL)&&(head->right==NULL)){// only one node, 
		return 1;
	}else{
		return nodeNumber(head->left)+nodeNumber(head->right);
	}	

}

int main(void){
	struct node *head=NULL,A={NULL,'A',NULL},B={NULL,'B',NULL},C={NULL,'C',NULL},D={NULL,'D',NULL},E={NULL,'E',NULL},F={NULL,'F',NULL};
	
	head=&A;
	A.left=&B; A.right=&C;
	B.left=&D; B.right=&E;
	C.left=&F;
		
	printf("node number:%d\n",nodeNumber(head));	
	
	
	
	
}
