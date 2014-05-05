#include <stdio.h>
#include <string.h>

int find(char array[],char key,int n){

	
	if(n==-1) return -1;
	else if(array[n]==key) return n;
	else return find(array,key,n-1);
	

	}


int main(void){
	
	char str[10]={'a','b','c','d','e','f','g','h','i','j'};

	printf("the position of g is %d\n", find(str,'a',10));


	return 0;
}
