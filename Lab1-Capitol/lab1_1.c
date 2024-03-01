//Laboratori 1_1
//programa rebi dos valors M i N, comprovar que siguin nombres enters
//altrament escriu un missatge informatiu i finalitzara amb un -1
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


void main(int argc,char*argv[]){
    
    if(argc!=3){
        printf("%s El programa necessita dos valors d'entrada\n",argv[0]);
    }
    else{
        int M,N;
        M=atoi(argv[1]);
        N=atoi(argv[2]); //un replicant miri si es un nombre mes gran a 0 sino finalitza -1
        int pid;
        pid=fork();
        if(pid==-1){
            //Error en fer la instruccio fork()
            printf("Hi ha agut un error en la crida del fill");
        }
        else if(pid==0){
            if(N>0){
                //Comprovar que el nombre N sigui un enter
                printf("El nombre donat %d es un enter, comprovat per un replicant\n ",N);
            }
            else{
                //El nombre donat N no es un enter
                printf("El nombre donat %d  NO es un enter, comprovat per un replicant\n ",N);        
            }
        }
    }
}