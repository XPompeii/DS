#include <stdio.h>
#define GRADE 3
#define CLASS 5
#define SUBJECT 2


int main(void){

	int score[GRADE][CLASS][SUBJECT]={
		{{90,100},{95,100},{90,91},{90,96},{100,90}},
		{{90,100},{93,100},{90,92},{90,97},{100,90}},
		{{90,100},{91,100},{90,93},{90,98},{100,90}}
		};
	int i,j,chi[GRADE]={0,0,0},eng[GRADE]={0,0,0},sumchi=0,sumeng=0;

	for(i=0;i<GRADE;i++){
		sumchi = 0;
		sumeng = 0;
		for(j=0;j<CLASS;j++){
		sumchi += score[i][j][0];

		sumeng += score[i][j][1];
		
	}
	chi[i] = sumchi/CLASS;
	eng[i] = sumeng/CLASS;
	}

	for(i=0;i<GRADE;i++){
		printf("The AVG chinese of Grade %d: %d\n",i+1,chi[i]);
		printf("The AVG english of Grade %d: %d\n",i+1,eng[i]);

	}	

	return 0;
}
