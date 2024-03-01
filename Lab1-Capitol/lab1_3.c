//Laboratori 1_3
//Replicants finalizen amb 0 si la comprovacio del valor N que els hi ha passat TT es un exit
// si N es mes gran o igual a 0, la missio frassat si N es mes petit a 0 i finalitza amb un -1
//TT esperar els seus replicants que acabin la missio--> si un fracasa missatge informatiu
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void main(int argc, char *argv[]){
    if(argc!=3){
        printf("%s El programa necessita dos valors d'entrada\n",argv[0]);
    }

    else{
        int M,N;
        M=atoi(argv[1]);    //Crear M replicants amb valor N cadascu (passar de argv[i] a int)
        N=atoi(argv[2]);    
        int pid;
        int stat,codi;
        if(M>0){     //Comprovar que M i N siguin enters N
            for(int i=0;i<M;++i){       //crear M replicants 
                pid=fork(); 
                    if(pid==0){         //Replicant mirar si N es un enter-> Ho es
                        if(N>=0) {      //N es un enter
                            exit(0);
                        }  
                        else{           //N  NO es un enter
                            exit(-1);
                        }  
                    }
                    if(pid==-1){      //Error al crear el replicant
                    printf("Hi ha hagut un error en la crida del fill\n"); 
                    break;
                    }
            }
            for(int i=0;i<M;++i){
                //Esperar que els replicants acabin la missio-recollir estat de finalitzacio
                codi=0;                         //inicialitzar codi per cada replicant
                wait(&stat);                    //esperar que acabin els replicants
                if(WIFEXITED(stat)){            //Mirar si el replicant ha acabat be 
                    codi=WEXITSTATUS(stat);     //recuperar el valor del exit del replicant
                        if(codi==0){
                            //El replicant ha fet la missio amb exit(N>=0)
                            printf("Missio amb exit: Codi: %d \n",codi);
                        }
                        else{
                            //El replicant ha fracassat (N<0)
                            codi=-1;
                            printf("Missio fracasada: Codi: %d \n",codi);
                        }
                }
                else{               //Hi ha agut error en l'exit del replicant
                    printf("Error en exit del fill\n");
                }
            }   
        exit(0);
        }
        else{
            //Dels dos valors donats minim un d'ells no es enter 
            printf("%s Entra el primer valor M com a enter \n",argv[0]);
            exit(0);
        }
    }
}