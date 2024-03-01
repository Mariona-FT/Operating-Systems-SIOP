#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "dummy2.h"

#define TEAMNAME "mariona.farre"
#define ENIGMA1 "FFEE"

void main(int argc,char *argv[]){
	if (argc !=3){
		printf("%s necesita dos parametres\n", argv[0]);
    }   

	else{
	int M, N;
	int pid;
	M=atoi(argv[1]);
	N=atoi(argv[2]);
	int fitxer;

	if(M>0){//valor M ha de ser excusivament mes gran a 0-no es podran crear els replicants
		fitxer=dummy_open( );	//obrir el fitxer del dummy-entrar en el banc del temps
		
		for(int i=0;i<M;i++){		//fer M replicants a robar el temps
			pid = fork();			//crear els replicants

			if(pid==0){
				close(0);
				dup(fitxer);	//duplicar el fitxer del dummy
				execlp("./replicant","./replicant",argv[2],(char*) 0);
				close(fitxer);	//tancar el fitxer duplicat
			}
			if(pid==-1){
                printf("Hi ha un error el la creacio dels replicants\n");
                break;
            }
		}

		int acum=0;			//inicialitzar l'acomulador per guardar el temps
		int stat,resposta;
		resposta=waitpid(-1, &stat, 0); //resposta espera cada replicant + mira el seu estat stat
		
		while (resposta>0) {		//mentres hi haguin resposta dels replicants
			
			if(WIFEXITED(stat)){	//morar l'estat dels replicants
				int8_t codi=WEXITSTATUS(stat);
				acum += codi;
			}
			else{
                printf("Hi ha un error en l'exit dels replicants\n");
			}
		resposta = waitpid(-1, &stat, 0);	//tornar a esperar la resposta dels replicants
		}
		dummy_test(acum, ENIGMA1, TEAMNAME); //acabat l'atac processa tot el temps obtingut
		exit(0);							//acabar el programa

		}
		else{
			printf("El programa %s necessita el primer valor M com a enter\n", argv[0]);
		}
	}
}