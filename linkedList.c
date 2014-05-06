#include <stdio.h>

struct node{
				int data;
				struct node *next;
			};

void printList(struct node * head){
		// struct node * tempP; // I affraid that head would be changed ....
		//tempP=head;
		printf("the address of head(inside function) is %p\n",&head);	
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

int main(void){
	struct node * head;
	struct node A={10,NULL};
	struct node B={20,NULL};
	struct node C={30,NULL};
	struct node D={40,NULL};

	head=&A;
	A.next=&B;
	B.next=&C;
	C.next=&D;
    C.data=10;	
	//testing below
	printf("the address of head is %p\n",&head);	
	printf("head content is %p\n",head);
	printList(head);
	printf("******************************\n");
	printf("using countList function:%d\n",countList(head));
	printf("the address of head is %p\n",&head);	
	printf("after function call head content is %p\n",head);


	printf("******************************\n");
	printf("using updateList function:\n");
	updateList(head);
	printList(head);

	printf("******************************\n");
	printf("using reverseList function:\n");
	head = reverseList(head);
	printList(head);


	return 0;
}
