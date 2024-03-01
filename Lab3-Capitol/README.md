* Resultat i informació del laboratori en el fitxer:

   [Resultats_lab 3](https://github.com/Mariona-FT/Operating-Systems-SIOP/blob/main/Lab3-Capitol/Resultats_Lab%203.pdf)

1. Assegurar-nos que tenim els arxius dummy.h i libdummy.a al directori de treball

2. Com compilar el codi ?

```
gedit capitol.c
gcc capitol.c -o capitol
gcc TT.c -o TT -L. -ldummy3
gcc replicant.c -o replicant  -L. -ldummy3
```
