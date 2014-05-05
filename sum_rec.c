#include <stdio.h>

int sum(int array[],int n){
	
	if(n==0) return 0;
	else return sum(array,n-1)+array[n-1];
	

	}


int main(void){
	
	int num[10]={1,2,3,4,5,6,7,8,9,10};

	printf("1+2+3....+9+10= %d\n", sum(num,10));


	return 0;
}
