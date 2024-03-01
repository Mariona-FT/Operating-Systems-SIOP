//Laboratori 1_2
//El tt crei M replicant que rebrant un valor N cadascu
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
        M=atoi(argv[1]);    //Crear M replicants amb valor N cadascu (passar de argv[i] a int)
        N=atoi(argv[2]);    
        int pid;
        if(M>0 && N>0){     //Comprovar que M i N siguin enters N

            for(int i=0;i<M;++i){
                //crear M replicants 
                pid=fork(); 
                //utlitizar la instruccio fork() per crear els replicants i pid com a retorn d'aquest
                    if(pid==0){
                    printf("Aquest es el programa fill %d que li pasa un valor %d per mirar\n",getpid(),N);
                    //getpid() per mirar el pid del proces en execucio que serien els programes fills
                    //pero inecessari per aquest problema- simplement per comprovar que son programes fills
                    break;
                    }                    
                    if(pid==-1){
                    printf("Hi ha agut un error en la crida del fill\n"); 
                    break;
                    }
            }
        }
        else{
            //Dels dos valors donats minim un d'ells no es enter 
            printf("%s Entra dos valors enters com a parametres\n",argv[0]);
            exit(-1);
        }
    }
}