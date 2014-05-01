#include <stdio.h>
#include <string.h>
int printsumrec(int ma){
	int sum=0;
	static char printnum[200]="",temp[5]="";
	static int i=1;

	if(ma==1){
			sum =1;	
			sprintf(printnum,"%d",i++);
			printf("%s = %d \n",printnum,sum);
	        return 1;

	}else{
		 sum = printsumrec(ma-1)+ma; 
		 sprintf(temp,"+ %d",i++);
		 strcat(printnum,temp);
		 printf("%s = %d \n",printnum,sum);	  
		 return (printsumrec(ma-1)+ma); // can not be this
		 //return sum;
	}
}

void printsumloop(int ma){
	
	int i,sum=0;
	char printnum[200]="1",temp[5];
	
	for(i=1;i<=ma;i++){
		sum += i;

		/*if(i==1){
			sprintf(printnum,"%d",i);
			printf("%s = %d \n",printnum,sum);
		}
		else{*/
			sprintf(temp,"+ %d",i);
			strcat(printnum,temp);
			printf("%s = %d \n",printnum,sum);
	//	}	 
	}


}


int main(void){

	int max,sum;
	//static char print[200];	

	printf("enter a max number:");
	scanf("%d",&max);
	printf("using recursive \n");
    	
	printsumrec(max);
	
	printf("using loop \n");
	printsumloop(max);



	return 0;
}


