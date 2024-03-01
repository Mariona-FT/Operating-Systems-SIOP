* Resultat i informació del laboratori en el fitxer:

   [Resultats_lab 3]()

1. Assegurar-nos que tenim els arxius dummy.h i libdummy.a al directori de treball

```
gedit capitol.c
gcc capitol.c -o capitol
gcc TT.c -o TT -L. -ldummy3
gcc replicant.c -o replicant  -L. -ldummy3
```