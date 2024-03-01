* Resultat i informació del laboratori en el fitxer:

   [Resultats_lab 2](Operating-Systems-SIOP/Lab2-Capitol/Resultats_Lab 2.pdf)


1. Assegurar-nos que tenim els arxius dummy.h i libdummy.a al directori de treball

2. Com compilar el codi (p.ex. el programa myprog.c)?
```
-@ubiwan:~/SIOP/lab2$ ./gendummy
Usage: ./gendummy [S|M|L], to create SMALL, MEDIUM or LARGE dummy file
-@ubiwan:~/SIOP/lab2$

gcc replicant.c -o replicant -L. -ldummy2
gcc TT.c -o TT -L. -ldummy2
mariona@mariona/Escritorio/SIOP/Lab/Capitol-Lab1$ ./TT 2 3
```
