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
        printf("Stack is empty");
    }else{
        for(i=0;i<=top;i++){
            printf("%5d",stack[i]);
        }
        printf("\n");
    }

}

int push(int *stack,int n,int *top,int data){
    if(isStackFull(stack,n,top)){
        printf("Stack is full\n");
    }else
        top++;
        stack[top]=data;
    }
    return 1;
}


int main(void){
	
	int stack[STACK_SIZE];
	
	int i,top=-1;

	// below is for testing 
	for(i=0;i<STACK_SIZE;i++){
		printf("%3d",stack[i]);
	}
	
	if(isStackEmpty(stack,top))
		printf("stack is empty\n");
	else
		printf("stack is not empty\n");
		
		

	return 0;
}
