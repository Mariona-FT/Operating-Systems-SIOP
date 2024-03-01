#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/*
//1 a) limiti a fer un echo d'entrada estandar a la sortida estandar
int main(){
    char c;
    while(read(0,&c,sizeof(char))) //LLegir un caracter per entrada estandar 0
        write(1,&c,sizeof(char));   //escriure aquest mateix caracter per sortida estandar
}

// 1 b)  echo pero tecnica buffering llegint un buffer de MAX a MAX
#define MAX 20
int main(){
    char c[20];
    int n=0;
    while ((n=read(0,c,(MAX*sizeof(char))))>0) //n guardara el valor guardat llegit per pantalla
            //pel canal estandar 0 el char C 
     write (1,c,n);     //Escriu per pantalla el echo fet
}

// 1 c) Fa el echo codi una sola vegada i redireccionant els canals de manera que permeti
//el pas de parametres per indicar fitxer 
//Cap parametres (STDIN->STDOUT)//UN parametre (fitxer_in->STDOUT)//DOS parametres (fitxer_in->fitxer_out)
#define MAX 20
int main(int argc,char *argv[])
{
    char c[MAX];
    int fprimer,fsegon;
    int x=0;
    if(argc>1){
        close(0);   //redireccio del stdin al fitxer
        fprimer=open(argv[1],O_RDONLY);
        if(fprimer==-1){perror("Error\n");}
    }
    if(argc>2){
        close(1);   //redireccio del stdout al fitxer
        fsegon=open(argv[2],, O_RDWR | O_CREAT,S_IRWXU););
        if(fsegon==-1){perror("Error\n");}
    }
    while(x=read(0,c,(MAX*sizeof(char)))>0) write(1,c,x);
    close(0);
    close(1);
}*/
//5 busca z
#define MAX 20
int fi=0;
void rutina_alarma(int signo)
{
    fi = 1;
    char tmp[MAXMAX];
    sprintf(tmp,"Alarma exhaurida\n");
    if(write(1,tmp,strlen(tmp))<0) perror("Error al write\n");
}

int main(int argc,char *argv[]){
    int fd,i,x=0;
    if(argc!=2) exit(-1);
    if((fd=open(argc[1],O_RDONLY))<0) perror("Error al obrir\n");

    signal (SIGALRM,&rutina_alarma);
    alarm(3);
    char x[MAX];
    int buscarz=0;
    while((n=read(fd,x,MAX))>0) && fi==0 && buscarz==0){
        if(n<0) perror("Error al llegir\n");
        for(i=0,i<n;++i){
            if((x[i]=='z') && not fi){
                alarm(0);
                buscarz=1;      //trobada la z
                printf("S'ha trobat una z\n");
            }
        }
    }
    if(buscarz==0 && n==0){
        printf("NO s'ha trobat z\n");
    }
    close(fd);
}