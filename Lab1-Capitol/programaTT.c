#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "dummy.h"

void main(int argc, char *argv[]){
	if (argc !=3){
		printf("El programa %s necesita dos parametres\n", argv[0]);
    }
    
	else{
		int M, N;
		M = atoi(argv[1]);      //nombre de replicants a crear
		N = atoi(argv[2]);      //banc del temps-N unitats de temps a mirar
        int pid;
        int stat;
		if (M>0){               //valor M ha de ser excusivament mes gran a 0-no es podran crear els replicants

			for (int i = 0; i < M; i++){
				pid = fork();
				if (pid==0){
					execlp("./replicant","./replicant",argv[2],(char*)0);
                    break;
				}
                
                if(pid==-1){
                    //Reportar errors amb el fork
                    printf("Hi ha un error el la creacio dels replicants\n");
                    break;
                }
		    }
            for (int i=0;i<M;i++){
                wait(&stat);            //esperar que el replicant torni el seu resultat
                if (WIFEXITED(stat)){   //mirar l'estat dels replicants-sense error
                    int8_t codi = WEXITSTATUS(stat); //mirar el codi que passen els
                    if(codi==0){
                        //El replicant ha fet la missio amb exit(N>=0)
                        printf("Missio amb exit: Codi: %d \n",codi);
                    }
                    if(codi==-1){
                        //El replicant ha fracassat (N<0)
                        printf("Missio fracasada: Codi: %d \n",codi);
                    }
                }
                else{
                    //Reportar errors amb l'exit
                    printf("Hi ha un error en l'exit dels replicants\n");
                    }
                }
            exit(0);
	    }   
		else{
		printf("El programa %s necessita el primer valor M com a enter\n", argv[0]);
		}
	}
}
