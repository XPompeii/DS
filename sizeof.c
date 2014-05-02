#include <stdio.h>

void print(int array[]){
	
	printf("sizeof str : %d\n",sizeof array);
	printf("sizeof str[0] : %d\n",sizeof array[0]);


}


int main(void){
	
	int str[10]={1,2,3,4,5,6,7,8,9,10};

	printf("sizeof str : %d\n",sizeof str);
	printf("sizeof str[0] : %d\n",sizeof str[0]);
	
	printf("after throwing to function:\n");

	print(str);


}
