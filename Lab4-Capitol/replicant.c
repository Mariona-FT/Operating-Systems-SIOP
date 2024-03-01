#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>  
#include "dummy4.h"


void main (int argc, char *argv[]){
	 int N,bytesllegits;
	if (argc !=2){
		//el programa necessita estrictament dos arguments 
		printf("%s el replicant necessita un parametre a mirar\n", argv[0]);
	}
    else{
		N = atoi(argv[1]);
		char* buffer=malloc(N);
		if(N > 0){
			dummy_init(buffer, N); //treure els bytes a robar
			while((bytesllegits = read(0,buffer, N))>0){
				dummy_calc(buffer, bytesllegits); //transformar els bytes robats a temps real
			}
		dummy_end(); //exit del replicant amb missio exit
		}
		else {
			exit(-1); //exit del replicant amb missio fracassada
		}
	}
}