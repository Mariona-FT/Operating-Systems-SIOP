#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "dummy.h"

void main(int argc, char *argv[]){
	if (argc!=2){
		printf("%s el replicant necessita un parametre a mirar\n", argv[0]);
	}

	else{	
		int N, final;
		char buffer[1500];
		
		N = atoi(argv[1]);                 //agafar el temps donat-N

		if (N>=0 && N<=1500){
			dummy_ini( buffer, N );      //Inicialitzacio del buffer-funcio donada dummy
			final = 0;
			while (!final){
				final = dummy_cpt( buffer, N ); //Mirar el cpt del buffer amb N-funcio donada dummy
			}
			dummy_end();                //Tanca el dummy-funcio donada dummy
			exit(0);
		}
		else{
			exit(-1);						//N es menor a 0 --> missio fracassada
		}
	}
}
