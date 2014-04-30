#include <stdio.h>

int gcd(int a,int b);

int main(void){
	
	int first,second,gcdn;
	
	printf("please enter 2 integer:");
	scanf("%d%d",&first,&second);

	if(first>second)
		gcdn=gcd(first,second);
	else
		gcdn=gcd(second,first);

	printf("( %d, %d ) = %d\n",first,second,gcdn);


}

int gcd(int a,int b){
	
	if((a%b)==0) return b;
	else return (gcd(b,a%b));

	
}
