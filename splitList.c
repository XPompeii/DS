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
	while(head->next != NULL){
		
		printf("%3d",head->data);
		head=head->next;

	}
	printf("%3d",head->data);
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

int main(void){
	struct node * head=NULL,*h1=NULL,*h2=NULL;// it's better to initialize pointer to NULL!!!
	struct node A={2,NULL};
	struct node B={4,NULL};
	struct node C={5,NULL};
	struct node D={7,NULL};
	NODE E={8,NULL};

	head=&A;
	A.next=&B;
	B.next=&C;
	C.next=&D;
    D.next=&E;	
	//testing below
	printf("before function splitlist:\n");
	printList(head);
	splitList(head,&h1,&h2);
	printf("after function splitlist:\n");
	printf("printList(head)");
	printList(head);
	printf("printList(h1)");
	printList(h1);
	printf("printList(h2)");
	printList(h2);
	

	return 0;
}
