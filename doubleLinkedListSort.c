#include <stdio.h>
#define DLLTYPE int

typedef struct node{
				struct node *pre;
				DLLTYPE data;
				struct node *next;
			}NODE;

void printList(struct node * head){
		// struct node * tempP; // I affraid that head would be changed ....
		//tempP=head;
		//printf("the address of head(inside function) is %p\n",&head);	
		printf("Printing struct linked list:\n");
	if(head==NULL)
		printf("linked list is empty!\n");
	while(head!= NULL){
		
		printf("%3d",head->data);
		head=head->next;

	}
	
	printf("\n");
}

/*int countList(struct node *head){
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
}*/

// this function to check if there is really a p element in the Linked List to prevent problem happens
int isPosInLinkedList(NODE *head,NODE *pos){
	while(head!=NULL){
		if(head->data==pos->data)
			return 1;
		head=head->next;
	}
	return 0;

}


void insertDoubleList(NODE **head,NODE *pos,NODE *datap){
	NODE *tail=NULL;
	if(*head==NULL){// if LL Is empty
		*head=datap;
		datap->next==NULL;
		datap->pre==NULL;
	}else{// LL is at least one element
		if(pos->next != NULL){ //there is nothing after  insert position 
			if(isPosInLinkedList(*head,pos)){
			datap->next = pos->next;
			datap->pre=pos;
			pos->next->pre=datap;
			pos->next=datap;
			}
			}else{ // insert position is in the midddle
			if(isPosInLinkedList(*head,pos)){
			pos->next=datap;
			datap->pre=pos;
			datap->next=NULL;
			}else{
			printf("there is no such element in the Linked List!!\n");
			
			}
		}
	}	
}

void deleteDoubleList(NODE **head,NODE *pos){
	if(isPosInLinkedList(*head,pos)){
		if(pos==*head){
			*head=pos->next;
		}else{
			pos->pre->next=pos->next;
			if(pos->next!=NULL)
				pos->next->pre=pos->pre;
		}
	}else{
		printf("there is no such element in the Linked List.\n");
	}
	
}

void DoubleListSort(NODE **head,NODE *datap){
	NODE *pos=NULL;
	NODE *tail=NULL;
	tail=*head;

	while(((datap->data)>(tail->data))&&(tail->next!=NULL)){//stop when insert data is bigger than one of its element 
		tail=tail->next;
	}


	
	if(tail->data<datap->data){//if insert element is bigger than all of the element and insert at the last position
		tail->next=datap;
		datap->pre=tail;
		datap->next=NULL;		
		}else if(tail->pre== NULL){
		pos=*head;
		pos->pre=datap;
		datap->next=pos;
		*head=datap;
		datap->pre=NULL;	
		}else{
		insertDoubleList(head,tail->pre,datap);

		}	
}

int main(void){
	struct node * head=NULL,*p=NULL,*q=NULL;
	struct node A={NULL,10,NULL};
	struct node B={NULL,20,NULL};
	struct node C={NULL,30,NULL};
	struct node D={NULL,40,NULL};
	struct node X={NULL,99,NULL};

	
	//testing below
	printf("adding first element D into to LL\n");
	insertDoubleList(&head,head,&D);
	printList(head);
	printf("******************************\n");
	printf("adding second element B \n");
	DoubleListSort(&head,&B);
	printList(head);


	printf("******************************\n");
	printf("adding C \n");
	DoubleListSort(&head,&C);
	printList(head);


	printf("******************************\n");
	printf("adding A\n");
	DoubleListSort(&head,&A);
	printList(head);

	printf("******************************\n");
	printf("adding X\n");
	DoubleListSort(&head,&X);
	printList(head);

	

	
	return 0;
}
