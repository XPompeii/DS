#include <stdio.h>

void printStar(int n,int m,int d){
	int i,j;

	for(i=1 ; i <= m ; i++){
		for(j=1 ; j <= n ; j++){
			if(i>d && i<=m-d && j>d && j<=n-d)
				printf(" ");
			else
				printf("*");

		}
		printf("\n");
	}
}

int main(void){
	
	int m,n,d;
	n=10;	
	m=8;
	d=2;	

    printStar(n,m,d);	


return 0;
}
