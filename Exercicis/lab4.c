#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>

int main (int argc, char *argv[]){
    int fitxer;
    int bytesread;
    char c;
    int par=0;
    if(argc != 2){
            fprintf(stderr,"Usage: %s file_name\n",argv[0]);
        }
    fitxer=open(argv[1],O_RDONLY);
    
    if(fitxer==-1) { //error
        fprintf(stderr," S'ha produit un error al obrir el fitxer%s\n",argv[1]);
        }

    while((bytesread=read(fitxer,&c,1))>0){
        if(par==1){
            if(write(1,&c,1)<0){ //error
            fprintf(stderr,"Hi ha un error al escriure \n");
            }
        }
        if (c==’\n’){
        if(par==0) par=1;
        else par=0;
        }
    }
    if (bytesread == -1){ //error
        fprintf(stderr,"S'ha produit un error al llegir el fitxer \n");
    }
exit(1); 
close(fitxer);
}