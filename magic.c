#include <stdio.h>

void printm(int array[][5],int n){
	
	printf("Magic Square of size %d:\n",n);
//	array[0][0]=3;
//	array[0][n/2]=1;
	
	int i,j;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			
			printf("%5d",array[i][j]);

		}
			printf("\n");
	}


}



int main(void){
	int snum;

	printf("Enter the size of the square:\n");
	scanf("%d",&snum);

	int matrix[snum][snum];
    matrix[0][0]=0;
	printm(matrix,snum);


	return 0;
}
