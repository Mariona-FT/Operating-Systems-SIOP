#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
printf("Abans exec (pid=%d)\n",getpid());
execlp("./ex1","ex1",(char*)NULL);
printf ("Despres exe (pid=%d)\n",getpid());
} 
