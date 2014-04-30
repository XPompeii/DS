#include <stdio.h>


int readnum(void){
	int num;
	printf("please enter an odd integer:");
	scanf("%d",&num);    
	while(num % 2 == 0){
	printf("The number %d is not an odd number \n",num);	
	printf("please enter an odd integer:");
	scanf("%d",&num);    
	}	
	    

	return num;
}

void tristar(int ma){
	int i,j;	
	for(i=1;i<=ma;i++){
		for(j=1;j<=ma;j++){
			if(j<((ma+1)/2+1)-i || j> (ma-(ma+1)/2)+i || j < i-(ma-(ma+1)/2) || j> (ma+(ma+1)/2)-i )
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}


}


int main(void){
	int max;
	max = readnum();
	printf("max is %d \n",max);	
	tristar(max);

	return 0;
}



