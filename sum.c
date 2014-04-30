#include <stdio.h>

int sumloop(int n){
	int i,sum=0;
	for(i=1;i<=n;i++){
		sum+=i;
	}
	return sum;
}

int sumrec(int n){
	if(n==1) 
		return 1;
	else
		return sumrec(n-1)+n; 
}


int main(void){
	
	printf("1+2+3+....+100=%d  Using loop\n",sumloop(100));
	 

	printf("1+2+3+....+100=%d  Using recursive\n",sumrec(100));


	return 0;
}
