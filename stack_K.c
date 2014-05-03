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
	    printf("The stack is:\n");
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

void deleteA(int *stack,int a,int *topp,int *datap){
	int i,j,temp_top=-1,tempdata;
	int temp[STACK_SIZE];
	if(isStackEmpty(stack,*topp)){
		printf("The stack is empty.\n");
	}else{
		for(i=0;i<=*topp;i++){
			if(stack[i]==a){//if match!!
				for(j=*topp;j>i;j--){ // pop upper contents to temp stack
					pop(stack,topp,datap);
					push(temp,STACK_SIZE,&temp_top,*datap);
				}
				pop(stack,topp,datap);// delete match word
				for(j=temp_top;j>=0;j--){ // pop back the contents
					pop(temp,&temp_top,&tempdata);
					push(stack,STACK_SIZE,topp,tempdata);
				}
			}	
		}
	}
	

}

int pushK(int *stack,int n,int *topp,int k,int data){
	int i,j,temp_top=-1,tempdata;
	int temp[STACK_SIZE];
	if(isStackFull(stack,STACK_SIZE,*topp)){
		printf("The stack is full.\n");
		return 0;
	}else{
				for(j=*topp;j>=k-1;j--){ // pop upper contents to temp stack
					pop(stack,topp,&tempdata);
					push(temp,STACK_SIZE,&temp_top,tempdata);
				}
				push(stack,STACK_SIZE,topp,data);// insert k into stack
				for(j=temp_top;j>=0;j--){ // pop back the contents
					pop(temp,&temp_top,&tempdata);
					push(stack,STACK_SIZE,topp,tempdata);
				}
			}	
		
   return 1;
}	

int popK(int *stack,int *topp,int k,int *data){
	int i,j,temp_top=-1,tempdata;
	int temp[STACK_SIZE];
	if(isStackFull(stack,STACK_SIZE,*topp)){
		printf("The stack is full.\n");
		return 0;
	}else{
				for(j=*topp;j>=k;j--){ // pop upper contents to temp stack
					pop(stack,topp,&tempdata);
					push(temp,STACK_SIZE,&temp_top,tempdata);
				}
				pop(stack,topp,data);// pop k position into data
				for(j=temp_top;j>=0;j--){ // pop back the contents
					pop(temp,&temp_top,&tempdata);
					push(stack,STACK_SIZE,topp,tempdata);
				}
			}	
		
   return 1;
}	

int main(void){
	
	int stack[STACK_SIZE];
	int A=1,B=2,C=3,D=4,E=5,F=6;
	int i,top=-1,data;

	// below is for testing 
	/*for(i=0;i<STACK_SIZE;i++){
		printf("%3d",stack[i]);
	}*/
	

		
	if(push(stack,STACK_SIZE,&top,A))
		printf("push %d successfully\n",A);
	else
		printf("push failed\n");
	
	push(stack,STACK_SIZE,&top,C);
	push(stack,STACK_SIZE,&top,B);
	push(stack,STACK_SIZE,&top,A);
	push(stack,STACK_SIZE,&top,D);
	push(stack,STACK_SIZE,&top,F);
	

	printf("top now is %d\n",top);
	printStack(stack,top);

    printf("***************************\n");
	printf("Try delete 1 in the stack\n");
	deleteA(stack,A,&top,&data);
	printStack(stack,top);

    printf("***************************\n");
	printf("Try to push 1 into 2(second) position in the stack\n");
	pushK(stack,STACK_SIZE,&top,2,A);
	printStack(stack,top);

    printf("***************************\n");
	printf("Try to pop out 1(first) position in the stack\n");
	popK(stack,&top,1,&data);
	printStack(stack,top);

	return 0;
}


