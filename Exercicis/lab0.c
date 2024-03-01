//Laboratori 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void  main(int argc,char* argv[]){
	fwrite();
	if (argc!=3){
		printf("%s Es necessiten 3 arguments\n",argv[0]);
		}
	else{
		int num1,num2;
		num1=atoi(argv[1]);
		num2=atoi(argv[2]);
	if(num1> 0 && num2> 0){
		printf("Els nombres %d i %d son mes grans que 0\n",num1,num2);
	}
	else{
		printf("%s necesita dos parametres majors que 0\n",argv[0]);
	}
	}
}
