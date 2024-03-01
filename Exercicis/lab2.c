#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#define MAX 20
int llegir_comanda(char *com){  //funcio donada
    int len=0;
    char tmp[80];
    sprintf(tmp,"Escriu una comanda acabada amb Ctrl-D (exit per sortir)\n");
    write(1,tmp,strlen(tmp));
    if((len=read(0,com,MAX))==-1){
    printf("Error al llegir comanda\n");
    }
    return len;
}

void EscribeExitCode(int pid, int code)
    {
    int statuscode,signcode;
    char buffer[90];
    if (WIFEXITED(code)){
    statuscode=WEXITSTATUS(code);
    sprintf(buffer,"El proces fill %d  ha acabat amb el exit %d\n",pid,statuscode);
    write(1,buffer,strlen(buffer));
    }else{
    signcode=WTERMSIG(code);
    sprintf(buffer,"El proces fill %d  ha acabat amb el signal %d\n",pid,signcode);
    write(1,buffer,strlen(buffer));
    }
}
int main() {
    char buff[MAX];
    int comanda;
    int pid;
    int exitcode;
    while{
    comanda=llegir_comanda(buff);
    if (comanda>0) {
    if (strcmp(buff,"exit")==0)
        exit(0);
    if(fork()==0){
        printf("Executant %s amb PID=%d...\n",buff,getpid());
        execlp(buff,buff,NULL);
        printf("Error en executar comanda\n");
    }else{
        if((pid=wait(&exitcode))==-1) 
            printf("Error en wait\n");
        else
            EscribeExitCode(pid,exitcode);
        }
    }
    }
}
/*********************************************/
void LanzaComando(char *buff) {
    int pid;
    pid=fork();
    if (pid==0){

    execlp(buff,buff,NULL);
    perror("Exec FAILS\n");
    exit(100);
    }else if (pid<0){
    perror("FORK FALLA\n");
    exit(1);
    }
}
int main() { 
        
    char buff[MAX];
    int num,pid;
    int exitcode;
    while(1)
    {
    num=llegir_comanda(buff);
    if (num>0)
    {
    if (strcmp(buff,"exit")==0) //Sortir si s’escriu exit
    exit(0);
    if(buff[num-1]==’&’) //Mode background
    {
    buff[num-1]=’\0’; //Eliminem &
    LanzaComando(buff);
    }
    else //Mode foreground
    {
    LanzaComando(buff);
    EscribeExitCode(pid,exitcode);
    }
    }
    //Esperem tots el fills que han acabat
    while((pid=waitpid(-1,&exitcode,WNOHANG))>0)
    EscribeExitCode(pid,exitcode);
    }
}
/**********************************/
int main() {
    char buff[MAX];
    int num,pid;
    int exitcode;
    int alarma2seg;
    signal (SIGALRM,alarma2seg);
    while {
    num=llegir_comanda(buff);
    if (num>0) {
    if (strcmp(buff,"exit")==0)
    exit(0);
    buff[num-1]=’\0’; 
    }
    else {
    while((pid=waitpid(pid,&exitcode,0))>0){
        EscribeExitCode(pid,exitcode);
    }
    alarm(10);
    while(alarma2seg==0) pause();
    alarma2seg=0;
    }
    }
}
