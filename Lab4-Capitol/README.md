* Info per la SIOP challange:


Modificacions al TT:

- #define SERVNAME "SIOP-server"

- #define SERVADDR "-"

- #define SERVPORT 9999

- #define CRTLPORT 9900

- #define TEAMNAME "" // insert between "" your team name

- #define ENIGMA3 @// replace simbol @ with solution of enigna 3

- #define SILVERKEY ""  // insert SILVERKEY between ""

- #define GOLDKEY "" // use only for SIOP Challenge : insert GOLDKEY between ""


Afegir en main:

/*********  connection to Capitol ************************/

ctrlfd= funció ctrlconnect(SERVADDR,CTRLPORT,ENIGMA3, TEAMNAME, SILVERKEY, GOLDKEY);
/*retorna el file descriptor del canal de control i verifica l'enigma i la clau

fd = connecta(SERVADDR,SERVPORT); 
/*retorna el file descriptor del canal de dades


substituir dummy_testing() per:

/*******sending acum to capitol *******************/

nbytes=sprintf (buf, "%d", acum);
write(ctrlfd,buf,nbytes);

/*******reading answer from Capitol **************/

len=read(ctrlfd,buffy,128);
buffy[len]='\0';
printf("MISSION: %s\n",buffy);
