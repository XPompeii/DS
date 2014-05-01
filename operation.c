#include <stdio.h>
#include <string.h>


int cal(char opa[]){
	int i,num,result=0;
	num = opa[0]-'0';
	char oper;

	for(i=1;i<=strlen(opa);i++){
		    if(opa[i]<='9' && opa[i]>='0'){
				if(i==strlen(opa)){
						switch (oper)
						{
						case '+' :
						result = result+num;
						i++;
						break;
					case '-' :
						result = result-num;
						i++;
						break;
					case '*' :
						result = result*num;
						i++;
						break;
					case '/' :
						result = result/num;
						i++;
						break;
					}
					
				}else{
				num = num*10+(opa[i]-'0');			
				}
			}else{ // not number 
				//printf("%d \n",i);
				if(result==0){
				result = num;
				oper = opa[i];
				num = opa[i+1]-'0';
				i++;
				//printf("%c \n",oper);
				}else{
					switch (oper)
					{
					case '+' :
						result = result+num;
						oper = opa[i];
						num = opa[i+1]-'0';
						i++;
						break;
					case '-' :
						result = result-num;
						oper = opa[i];
						num = opa[i+1]-'0';
						i++;
						break;
					case '*' :
						result = result*num;
						oper = opa[i];
						num = opa[i+1]-'0';
						i++;
						break;
					case '/' :
						result = result/num;
						oper = opa[i];
						num = opa[i+1]-'0';
						i++;
						break;
					}
				}
			}
		
		}	
	//printf("oper = %c \n",oper);
	return result;
}


int main(void){
	char operation[20]="121*30/100";

	printf("%s the result is %d \n",operation,cal(operation));


	return 0;
}


