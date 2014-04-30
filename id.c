#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse_str(char * );// 0 is unsuccessful and 1 is successful:
int parse_int(int arr);

int main(void){
	char str[20];
	int arr;
	printf("please enter an 8 digit number:");
	scanf("%d",&arr);
	
	if(parse_int(arr))
		printf("using parse_int confirm this is real num \n");
	else
		printf("this is not true num using parse_int \n");

	printf("please enter again an 8 digit number:");
	scanf("%s",str);
	
	if(parse_str(str))
		printf("using parse_str confirm this is real num \n");
	else
		printf("this is not true num using parse_str \n");
	



	return 0;
}

int parse_str(char * stra){
	char token;
	int temp;
	int sum=0,length,i;
	length=strlen(stra);
	for(i=0;i<length-1;i++){
		token = stra[i];
		temp = atoi(token);
		sum += temp*(length-i);


	}
	if((sum%10)==(stra[length-1]-'0')) return (1);
	else return (0);

}

int parse_int(int arr){
	int i,sum=0, remainder;
	remainder = arr %10;
	arr /= 10;
	for(i=0;i<7;i++){
		sum += (arr%10)*(i+2);
		arr /= 10;

	}
	if(sum%10==remainder) return (1);
	else return (0);
}


