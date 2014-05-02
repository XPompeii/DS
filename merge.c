#include <stdio.h>
#define fSize 6 

void merge(int a[],int b[], int out[]){
	int i,j,k,max=0,index=0;
	printf("sizeof a = %d sizeof b = %d\n",(sizeof a),(sizeof b));
	printf("sizeof a[0] = %d sizeof b[0] = %d\n",sizeof a[0],sizeof b[0]);

	for(i=0;i< fSize ;i++){
			
			max=a[i];// let the first element of first array be max	
			while(a[i]<b[j]){ //if first element of second array is bigger than a[0]
				max = b[j]; // then replace the max value
				out[index++]=max; // fill in the output array
				printf("inner index:%d max:%d\n",index,max);	
				
				j++; // adding the index of second array
			}
			if(a[i]>b[j]){ // when a[i] >= b[j]

			out[index++]=a[i];
			printf("outer index:%d a[i]:%d\n",index,a[i]);
			}else{ // only a[i] = b[j]
				out[index++]=a[i];
				j++;
				printf("same: a[i]= %d\n",a[i]);
			}	
	}
	
	for(k=0;k<index;k++){ // iteration out result
		printf("%d/",out[k]);
	}
	
}



int main(void){
	int first[]={128,34,23,17,10,0};
	int second[]={1352,129,127,34,23,17,9,8,0};

	int result[100];

	merge(first,second,result);



	return 0;
}
