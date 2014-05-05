#include <stdio.h>

/*int binary(int array[],int key,int left,int right){
	int min;	


	if(left<=right){
		min = (left+right)/2;
		if(array[min]==key) return min;
		else if(array[min]>key) return binary(array,key,left,min-1);
		else return binary(array,key,min+1,right);		

	

	}else{ // when left > right !!
		return -1;
	}

}*/

int binaryw(int array[],int key,int left,int right){
	int min;
	

	while(left<=right){
	    min = (left+right)/2;
		
		if(array[min]==key) return min;
		else if(array[min]>key) right=min-1;
		else left=min+1;

	}

	return -1;

}


int main(void){
	
	int val[10]={5,12,34,56,76,81,99,123,145,168};

	printf("the position of %d is %d\n",168,binaryw(val,168,0,9));

	

	return 0;
}
