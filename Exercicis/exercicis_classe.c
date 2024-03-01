//exercici classe

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*
int main(){

    int pid;
    printf("Abans fork (pid=%d)\n",getpid()); //Aconseguir el pid
    pid=fork(); //Fer un nou porces amb amb el fork
    if(pid==0){
        //Si el pid es diferent es el FILL del proces que la inicialitzat
        printf("Despres fork (pid=%d) soc en fill\n",getpid());
    }
    else{
        //si el pid es diferent a 0 es el pare (si es -1 es ERROR)
        printf("Despres forl (pid=%d) soc el pare \n",getpid()); 
    }
}*/
/**********************************************/
int main(int argc, char *argv[])
{
int pid1, pid2, fd[2];
char s1[] = "izquierda";	//inicialitzar s1
char s2[] = "derecha";		//inicialitzar s2
if (argc!=2){				//si crida incorrecte no pot entrar res
printf("Paràmetres incorrectes\n");
exit(-1);
}
if ((pid1=fork()) > 0) pid2 =fork();	//creació dels fills pid1= fill 1 pid2=fill 2
if (pid1 == 0) {			//si es rep abans dreta
if (strcmp(argv[1],s1) == 0) kill(getppid(), SIGKILL); 	//matar a pare
else while(1);					//esperar que acabi d’executarse 
printf("He matat al meu pare\n");		//sortida que ha matat el seu pare
exit(-1);		//sortir
}
if (pid2 == 0)			//si rep el esquerra abans
{
if (strcmp(argv[1],s2)==0)
kill(pid1, SIGKILL);				//mata el pid1=el germà de pid2
else while(1);					//mentre ho hagi fet
printf("He matat al meu germa1\n");		//sortida que ha matat el germà
exit(-1);	//sortir
}
wait(NULL);		//no esperar a cap fill
wait(NULL);		//no esperar a cap fill
exit(0);		//acabar programa

