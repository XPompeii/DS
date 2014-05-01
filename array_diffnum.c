#include <stdio.h>

int count(int array[],int size){
	/*int i,j,count,result=0;

	for(i=0;i<size;i++){
		count=0;
		for(j=0;j<i;j++){
			if(array[j]!=array[i])
				count++;
			if(count==i){
				printf("%d \n",array[i]);//to print out diff num
				result++;
			}	
		}	
	}*/
	int i,j,count=1;
	
	printf("%d \n",array[0]);

	for(i=1;i<size;i++){
		for(j=0;j<i;j++){
			if(array[j]==array[i])
				break;
			
		}
		if(j==i){
			printf("%d \n",array[i]); // to confirm the number
			count++;
		}else{

			printf("same: %d \n",array[i]); // very good way to debug!!
		}

	}

		
	return count;
}


int main(void){
	int score[10]={10,20,40,20,50,10,60,30,10,10};
	int num;

	num = count(score,10);
	
	printf("the numbers of different number is: %d \n",num);

	return 0;
}
