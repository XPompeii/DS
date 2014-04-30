#include <stdio.h>

int evenSumRec(int num){
	if(num%2==0){
		if(num==2) return 2;
		else return evenSumRec(num-2)+num;
	}else{
		num = num-1;
		if(num==2) return 2;
		else return evenSumRec(num-2)+num;	
	}

}

int evenSumLoop(int num){
	int i,sum=0;
	if(num%2==0){
		for(i=1;i<=num;i++){
			if(i%2==0){
				sum += i;
			}
		}
	}else{
		num -= 1;
		for(i=1;i<=num;i++)
			if(i%2==0)
				sum += i;
	}
		return sum;
	}

int main(void){
	
	int sum,max;
	printf("please enter a max num:");
	scanf("%d",&max);
	sum = evenSumRec(max);
	printf("the even sum(by recursive) of %d is: %d \n",max,sum);
	sum = evenSumLoop(max);
	printf("the even sum(by loop) of %d is: %d \n",max,sum);

	return 0;
} 


