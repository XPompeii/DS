#include <stdio.h>
#include <string.h>
#define STACK_SIZE 10

int isStackEmpty(char *stack,int top){
	if(top==-1) return 1;
	else return 0;

}

int isStackFull(char *stack,int n,int top){
    if(top==n-1) return 1;
    else return 0;

}

void printStack(char *stack,int top){
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

int push(char *stack,int n,int *topp,char data){
    if(isStackFull(stack,n,*topp)){
        printf("Stack is full\n");
		return 0;
    }else{
        *topp=*topp+1; // be careful , it's *
        stack[*topp]=data;
    }
    return 1;
}

int pop(char *stack,int *topp,char *datap){
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
	
	char infix[20]="((A+(B*C))-D)";
	char word;	
	char stack[STACK_SIZE];
	
	int i,top=-1;
	char data;

	
	for(i=0;i<strlen(infix);i++){
		word=infix[i];
		switch(word){
		case '(' :
		case '+' :
		case '-' :
		case '*' :
		case '/' :
			push(stack,STACK_SIZE,&top,word);
			break;
		case 'A':
		case 'B':
		case 'C':
		case 'D':
        	printf("%c",word);
			break;
		case ')':
			pop(stack,&top,&data);
			while(data!='('){
			    printf("%c",data);
				pop(stack,&top,&data);
			}
			break;

		}
	



	}
		

	printf("\n");	

	return 0;
}


