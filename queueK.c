#include <stdio.h>
#define QUEUE_SIZE 20
#define QTYPE int

int isQueueEmpty(QTYPE *queue,int queueNo){
	if(queueNo==0) return 1;
	else return 0;

}

int isQueueFull(QTYPE *queue,int n,int queueNo){
    if(queueNo==n) return 1;
    else return 0;

}

void printQueue(QTYPE *queue,int front,int queueNo){
    int i;
    if(isQueueEmpty(queue,queueNo)){
        printf("Queue is empty\n");
    }else{
	    printf("printing queue content:");
        for(i=front+1;i<=front+queueNo;i++){
            printf("%3d",queue[i]);
        }
        printf("\n");
    }

}

int insert(QTYPE *queue,int n,int *rear,int *queueNo,int data){
    if(isQueueFull(queue,n,*queueNo)){
        printf("Queue is full\n");
		return 0;
    }else{
        *rear=(*rear+1)%n;
        queue[*rear]=data;
		*queueNo=*queueNo+1;
    }
    return 1;
}

int delete(QTYPE *queue,int n,int *front,int *queueNo,QTYPE *datap){
	if(isQueueEmpty(queue,*queueNo)){
		printf("Queue is empty\n");
		return 0;
	}else{
		*front = (*front +1)%n;
		*datap=queue[*front];
		*queueNo = *queueNo-1;
	}

	return 1;
}

int deleteqA(QTYPE *queue,int n,int *front,int *rear,int *queueNo){
	int i,start,end;
	start=(*front+1)%n;
	end=(*front+*queueNo)%n;
	QTYPE tempdata;
	printf("\n*front+1 = %d, *rear = %d,*front+ *queueNo= %d\n",*front+1,*rear,*front+*queueNo);
	for(i=start;i<=end;i++){
		//printf("\ni=%d\n",i);
		delete(queue,n,front,queueNo,&tempdata);
		if(tempdata==1){
		 //do nothing
		}else{
			 insert(queue,n,rear,queueNo,tempdata);
		}
	}
	

}

int deleteqK(QTYPE *queue,int n,int *front,int k,int *queueNo,QTYPE *datap){
	int i;
	if(k>*queueNo){
	printf("K is out of range\n");
	return 0;
	}else{
		for(i=*front+k;i>*front+1;i--){
			queue[i%n]=queue[(i-1)%n];
		}	
		*front=(*front+1)%n;
		*queueNo=*queueNo-1;	
		}
	return 1;
}


int main(void){
	
	QTYPE queue[QUEUE_SIZE];
	QTYPE A=1,B=2,C=3,D=4,E=5,F=6;
	int i,front=-1,rear=-1,queueNo=0;
	QTYPE data;

	//test below
	delete(queue,QUEUE_SIZE,&front,&queueNo,&data);	

	insert(queue,QUEUE_SIZE,&rear,&queueNo,A);
	insert(queue,QUEUE_SIZE,&rear,&queueNo,B);
	insert(queue,QUEUE_SIZE,&rear,&queueNo,C);
	insert(queue,QUEUE_SIZE,&rear,&queueNo,D);
	insert(queue,QUEUE_SIZE,&rear,&queueNo,E);
	insert(queue,QUEUE_SIZE,&rear,&queueNo,A);
	
	printQueue(queue,front,queueNo);
	printf("***************************\n");
	printf("after using deleteqA function:\n");
	deleteqA(queue,QUEUE_SIZE,&front,&rear,&queueNo);
	
	printQueue(queue,front,queueNo);
	printf("***************************\n");
	printf("\n");
	printf("after using deleteqK In fourth position function:\n");
	deleteqK(queue,QUEUE_SIZE,&front,5,&queueNo,&data);
	
	printQueue(queue,front,queueNo);
	
	
		

	return 0;
}


