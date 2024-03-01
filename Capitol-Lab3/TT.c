#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include "dummy3.h"

#define TEAMNAME "mariona.farre"
#define ENIGMA2 "SIGSTOP" // insert between "" solution of enigna 2
#define BRONCEKEY "7a645" // insert BRONCEKEY between

void main(int argc,char *argv[]){
	
	if (argc !=3){	//mirar si te dos parametres 2+1=necessita 3arguments exactament
		printf("%s necesita dos parametres\n", argv[0]);
		exit(-1);
    }
    
	else{
	int M, N;
	M=atoi(argv[1]);
	N=atoi(argv[2]);
	int c,pid;

	//valor M ha de ser excusivament mes gran a 0-no es podran crear els replicants
	if(M>0){
	
	//CAPITOL
    c = open("dummy.dat", O_RDONLY); //llegir en c el dummy.dat i obrir si nomes existeix
	if(dummy_checkfile(c)){	//mirar si el dummy file del temps es correcte

	//CREACIO PIPE
	int fd[2];
	pipe(fd);

	//envia senyal del capitol si esta a punt de robar
	signal(SIGUSR1,ready);

	int capitol=fork();
		if(capitol==0){ 	//entra si nomes es crea be el fork del capitol
			close(fd[0]);
			dup2(fd[1],1);
			dup2(c,0);
			close(c);
			close(fd[1]);
			execlp("./capitol","capitol",NULL);
		}
	close(fd[1]);
	int acum=0;

	//REPLICANTS
	for(int i=0;i<M;i++){		//fer M replicants a robar el temps
		pid=fork();
		if(pid==0){
			dup2(fd[0],0);
			close(fd[0]);
			execlp("./replicant","./replicant",argv[2],(char*)0);
		}
		if(pid==-1){
			printf("Hi ha un error a la creacio dels replicants\n");
			break;
		}
		//ACUMULADOR
		int stat,resposta,actual;
		while ((resposta=(waitpid(-1, &stat, 0)))>0){//resposta espera cada replicant + mira el seu estat stat
		actual=WIFEXITED(stat);
		if(actual!=0){ 
			int codi=(int8_t)WEXITSTATUS(stat);
			acum += codi; //acumular el resultats dels bancs robats
		}
		if(actual==-1){
			printf("Hi ha un error en l'exit dels replicants\n"); 
			exit(-1);
			}
		}
	}
	close(fd[0]);
	
	//acabat l'atac processa i comprova tot el temps obtingut
	int banc=dummy_testing(acum, ENIGMA2, TEAMNAME,BRONCEKEY); 
	if(banc==0){
		exit(0);
	}else{	//hi ha un error al comprovar el resultat trobat
		printf("Hi ha hagut un error al comprovar l'atac dels replicants\n");
		exit(-1);
		}
	}
	}else{ 
		printf("El programa %s necessita el primer valor M com a enter\n", argv[0]); 
		exit(-1);
		}
	} //primer else arguments==3
} //main
