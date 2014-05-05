#include <stdio.h>

int whileSeqSearch(char *array,int length,char key){

	int i=0;	

	while(key!=array[i] & i<length){
		
		i++;
	}

	if(i==length) return -1;
	else return i;
	

}


int main(void){
	
	char str[10]={'e','i','l','m','n','o','r','w','s','d'};

	printf("w: %d\n", whileSeqSearch(str,10,'d'));
		



	return 0;
}
