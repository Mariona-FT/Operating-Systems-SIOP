#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "dummy2.h"

void main (int argc, char *argv[]){
	if (argc !=2){
		printf("%s el replicant necessita un parametre a mirar\n", argv[0]);
	}

	else{
		int N, bytesllegits;
		char buffer[1500];
		N=atoi(argv[1]); 					//agafar el temps donat-N
		
		bytesllegits = 0;
		dummy_init(buffer,N);				//prepara el contenidor N de temps
		bytesllegits=read(0,buffer,N);	//llegir tots els bytes del banc del temps 

		while(bytesllegits>0){					//mentre hi haguin bytes llegits pel replicant
			dummy_comp(buffer,bytesllegits);	//convertir el temps robat a temps real
			bytesllegits = read(0,buffer,N);	//tornar a llegir el temps ara real
		}
		dummy_exit();		//dummy surt del capitol
	}
}