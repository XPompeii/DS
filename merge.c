#include <stdio.h>

void merge(int a[],int b[], int out[]){
	int i,j,max=0,index=0;
	printf("sizeof a = %d sizeof b = %d\n",sizeof a,sizeof b);

	for(i=0;i< sizeof a ;i++){
			
			max=a[i];	
			while(a[i]<b[j]){
				max = b[j];
				out[index++]=max;
				printf("inner index:%d max:%d\n",index,max);	
				
				j++;
			}
			if(a[i]>b[j]){

			out[index++]=a[i];
			printf("outer index:%d a[i]:%d\n",index,a[i]);
			}else{
				out[index++]=a[i];
				j++;
				printf("same\n");
			}	
	}
	
	for(i=0;i<sizeof out;i++){
		printf("%d/",out[i]);
	}
	
}



int main(void){
	int first[]={128,34,23,17,10,0};
	int second[]={1352,127,34,23,17,9,0};

	int result[100];

	merge(first,second,result);



	return 0;
}
