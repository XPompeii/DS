#include <stdio.h>
#define STACK_SIZE 10

int isStackEmpty(int *stack,int top){
	if(top==-1) return 1;
	else return 0;

}

int isStackFull(int *stack,int n,int top){
    if(top==n-1) return 1;
    else return 0;

}

void printStack(int *stack,int top){
    int i;
    if(isStackEmpty(stack,top)){
        printf("Stack is empty\n");
    }else{
	    printf("printing stack content:");
        for(i=0;i<=top;i++){
            printf("%3d",stack[i]);
        }
        printf("\n");
    }

}

int push(int *stack,int n,int *topp,int data){
    if(isStackFull(stack,n,*topp)){
        printf("Stack is full\n");
		return 0;
    }else{
        *topp=*topp+1; // be careful , it's *
        stack[*topp]=data;
    }
    return 1;
}

int pop(int *stack,int *topp,int *datap){
	if(isStackEmpty(stack,*topp)){
		printf("stack is empty\n");
		return 0;
	}else{
		*datap=stack[*topp];
		*topp=*topp-1;
	}

	return 1;
}


int main(void){
	
	int stack[STACK_SIZE];
	
	int i,top=-1,data;

	// below is for testing 
	/*for(i=0;i<STACK_SIZE;i++){
		printf("%3d",stack[i]);
	}*/
	
	if(pop(stack,&top,&data))
		printf("pop successfully, the data is %d\n",data);
	else
		printf("pop failed\n");

	if(isStackEmpty(stack,top))
		printf("stack is empty\n");
	else
		printf("stack is not empty\n");
		
	for(i=1;i<15;i++){	
	if(push(stack,STACK_SIZE,&top,i))
		printf("push %d successfully\n",i);
	else
		printf("push failed\n");
	}

	if(pop(stack,&top,&data))
		printf("pop successfully, the data is %d\n",data);
	else
		printf("pop failed\n");
	

	printf("top now is %d\n",top);
	printStack(stack,top);


	for(i=0;i<=top;i++){
		printf("%3d",stack[i]);
	}

	return 0;
}


