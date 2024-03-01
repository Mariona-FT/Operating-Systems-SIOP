#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    int fitxer,lectura=0;
    char *mall;
    int mida=0; 
    if (argc!=2) exit(-1); //error
    fitxer = open(argv[1],O_RDONLY);
    if(fitxer<0) { //error
        perror("S'ha produit un error al obrir el fitxer\n");}
    
    mida = lseek(fitxer,0,SEEK_END);
    mall= malloc(mida);

    lseek(fitxer,0,SEEK_SET);
    lectura=read(fitxer,mall,mida); 
    if(lectura < 0){     //error
        perror("Error al read\n");
    }else{
    for(int i=0;i<lectura;++i){
        if(write(1,&mall[i],sizeof(char))<0) //error
            perror("Error al write\n");
    }
}
close(fitxer);
}