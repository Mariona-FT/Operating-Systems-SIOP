#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>  
#include "dummy3.h"

int main(){
    char c;
    kill(getppid(),SIGUSR1);
    while (read(0, &c, 1) > 0){write(1, &c, 1);} //llegeix pel canal 0 
    //escriu el dummy.dat capitol escriu a stdout
    exit(0);
}