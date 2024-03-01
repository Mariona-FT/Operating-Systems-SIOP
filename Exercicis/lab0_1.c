//Laboratori 0
//programa comprovi dos nombres siguin enters
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc,char*argv[])
//argc=nombre d'arguments (nombres)
//argv[]=vector on estaran els nombres
{
    if(argc!=3){
        //sempre hi ha un argument mes => entren 2 +1 =3 arguments en argc
        printf("%s el programa necessita nomes dos nombres d'entrada\n",argv[0]);   
    }
    
    else{
        int x,y;
        x=atoi(argv[1]); //convertir els enters donats de strings a enters
        y=atoi(argv[2]);

        if(x>0 && y>0){
            //els enters donats si son enters 
            printf("Els nombres %d i %d son dos nombres enters sent mes grans que 0\n",x,y);
        }
        else{
            //minim un dels enters no es un enter
            printf("Els nombres %d i %d NO son dos nombres enters sent minim un mes petit que 0\n",x,y);
            printf("%s es necessita dos nombres majors a 0\n",argv[0]);
        }
    }

}