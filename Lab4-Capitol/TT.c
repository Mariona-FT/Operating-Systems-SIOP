#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include "dummy4.h"

#define SERVNAME "SIOP-server"
#define SERVADDR "147.83.159.200"
#define SERVPORT 9999
#define CTRLPORT 9900
#define TEAMNAME "mariona.farre"    // insert between "" your team name
#define ENIGMA3 "07F4"              // replace simbol @ with solution of enigna 3
#define SILVERKEY "ab385"   // insert SILVERKEY between 
#define GOLDKEY "" // use only for SIOP Challenge : insert GOLDKEY between 
//MISSION: SUCCESSFUL!!.GOLDKEY:0xdc0c5

void main(int argc,char *argv[]){
	if (argc !=3){	//mirar si te dos parametres 2+1=necessita 3arguments exactament
		printf("%s necesita dos parametres\n", argv[0]);
		exit(-1);
    }
    
	else{
	int M, N;
	M=atoi(argv[1]);
	N=atoi(argv[2]);
	
	//valor M ha de ser excusivament mes gran a 0-no es podran crear els replicants
	if(M>0){ 
    int ctrlfd;
    int fd;

	//CAPITOL
    ctrlfd = ctrlconnect(SERVADDR, CTRLPORT, ENIGMA3, TEAMNAME, SILVERKEY, GOLDKEY); 
    //retorna el file descriptor del canal de control i verifica l'enigma i la clau
    fd = connecta(SERVADDR,SERVPORT); 
    //retorna el file descriptor del canal de dades

    //REPLICANTS
    int pid;
	for(int i=0;i<M;i++){		//fer M replicants a robar el temps
			pid=fork();
			if(pid==0){     //nomes entrar si el fork del replicant es crea correctament
                close(0);
                dup(fd);
				execlp("./replicant","replicant",argv[2],(char*)0);
			}
    }
	//ACUMULADOR
    int stat,resposta,actual;
    int acum=0;         //l'acumlador on es guardaran tots els resultats dels replicants

    while ((resposta=(waitpid(-1, &stat, 0)))>0){	//resposta espera cada replicant + mira el seu estat stat
        actual=WIFEXITED(stat);                     //donar l'estat del replicant
        if(actual!=0){ 
            int codi=(int8_t)WEXITSTATUS(stat);     //codi sera resultat del replicant en int
            acum += codi;              //sumar tots els resultats dels replicants i guardarho en l'acumulador
        }
        if(actual==-1){
            printf("Hi ha un error en l'exit dels replicants\n"); 
            exit(-1);
        }
    }

	int nbytes;
    char buffy[1000];   //donar un limit de tamany
    char buf[1000];

    int len;
    nbytes=sprintf (buf, "%d", acum); //enviar l'acumulador en el capitol
    write(ctrlfd,buf,nbytes);
    
    len=read(ctrlfd,buffy,128);       //Finalment llegir la resposta del capitol
    buffy[len]='\0';    
    printf("MISSION: %s\n",buffy);
    
	}else{ 
		printf("El programa %s necessita el primer valor M com a enter\n", argv[0]); 
		exit(-1);
	}
	} //primer else arguments==3
} //main
