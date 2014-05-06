#include <stdio.h>

typedef struct node{
				int data;
				struct node *next;
			}NODE;

void printList(struct node * head){
		// struct node * tempP; // I affraid that head would be changed ....
		//tempP=head;
		//printf("the address of head(inside function) is %p\n",&head);	
		printf("Printing struct linked list:\n");
	//while(head->next != NULL){// not good writing
	while(head!=NULL){	
		printf("%3d",head->data);
		head=head->next;

	}
	
	printf("\n");
}

int countList(struct node *head){
	int count=1;
	struct node * temp;
	temp = head;
	while(temp->next != NULL){
		count++;
		temp = temp->next;
	}
	return count;

}

void updateList(struct node *head){
	while(head != NULL){ // Don't be affraid that head would be changed , because you use call by value
		if(head->data ==10)
			head->data = 26;

		head=head->next;	

	}

}

struct node * reverseList(struct node *head){
	struct node *p;
	struct node *q;
	p=head;// teacher's graph page 129
	q=head;
	p=p->next;	
	head->next=NULL;
	while(p!=NULL){
		q=p;
		p=p->next;
		q->next=head;
		head=q;
	}
	return head;
}

void splitList(NODE *head,NODE **h1,NODE **h2){
	NODE *tail1=NULL,*tail2=NULL;
	while(head!=NULL){
		if((head->data)%2==1&&*h1==NULL){
		*h1=head;
		 head=head->next;
		 tail1=*h1;
		 tail1->next=NULL;
		}else if((head->data)%2==0&&*h2==NULL){
		*h2=head;
		head=head->next;
		tail2=*h2;
		tail2->next=NULL;
		}else if((head->data)%2==1){
		tail1->next=head;
		tail1=head;
		head=head->next;
		tail1->next=NULL;
		}else if((head->data)%2==0){
		tail2->next=head;
		tail2=head;
		head=head->next;
		tail2->next=NULL;
		}
	}	

}

void push(NODE **top,NODE *newNode){
	NODE *tail1=NULL;
	if(*top==NULL){
	*top=newNode;
	//*top->next=NULL;
	}else{
	tail1=newNode;
	tail1->next=*top;
	*top=newNode;
	
	}
}

void pop(NODE **top){
	NODE *temp=NULL;
	if(*top==NULL){
	printf("stack is empty\n");
	}else{
	temp=*top;
	*top=temp->next;
	}

}

int main(void){
	NODE *head=NULL,*top=NULL,*rear=NULL;// it's better to initialize pointer to NULL!!!
	NODE A={1,NULL};
	NODE B={2,NULL};
	NODE C={3,NULL};
	NODE *newNode;
	newNode=&A;
	
	
	//testing below
	printf("push 1 into stack:\n");
	push(&top,newNode);
	printList(top);
	printf("push 2 into stack:\n");
	newNode=&B;
	push(&top,newNode);
	printList(top);
	printf("push 3 into stack:\n");
	newNode=&C;
	push(&top,newNode);
	printList(top);
	printf("pop 3 out of stack:\n");
	pop(&top);
	printList(top);
	printf("pop 2 out of stack:\n");
	pop(&top);
	printList(top);
	printf("pop 1 out of stack:\n");
	pop(&top);
	printList(top);
	printf("pop ...  out of stack:\n");
	pop(&top);
	printList(top);
	

	return 0;
}
