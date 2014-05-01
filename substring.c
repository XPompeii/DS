#include <stdio.h>
#include <string.h>

void cal(char pa[],char ch[]){
	int i,j;
	//printf("now is ok \n");
	for(i=0;i<strlen(pa);i++){
		// printf("%c \n",pa[i]);
		if(pa[i]==ch[0]){
			for(j=1;j<strlen(ch);j++){
				if(pa[i+j]!=ch[j]){
					break;
				}
			}
			if(j==strlen(ch)){
				printf("position: %d \n",i);
			}
			
		}	

	}


}


int main(void){
	char par[20]="This is a bookis";
	char chi[5]="is";
    printf("parent: %s \n",par);
    printf("child: %s \n",chi);
	
	
	cal(par,chi);	




	return 0;
}
