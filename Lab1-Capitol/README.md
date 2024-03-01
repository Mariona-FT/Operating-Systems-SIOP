* Resultat i informació del laboratori en el fitxer:

   [Resultats_lab 1](Operating-Systems-SIOP/Lab1-Capitol/Resultats_Lab 1.pdf)


1. Assegurar-nos que tenim els arxius dummy.h i libdummy.a al directori de treball

2. Com usar les funcions dummy?

    Primera línia del programa:
    #include "dummy.h"
    
    I ja podeu usar les funcions
    dummy_ini( ... );
    dummy_cpt( ... );
    dummy_end();
    on sigui convenient.

3. Com compilar el codi (p.ex. el programa myprog.c)?
```
gcc myprog.c -o myprog -L. -ldummy
```
