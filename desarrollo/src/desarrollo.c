/*
 ============================================================================
 Name        : desarrollo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * archivo;


void leerInstrucciones(char * path_archivo)
{
 char * contenido_archivo;
 int tamanio;
 FILE* ejecutable=fopen(path_archivo,"r");
 if (ejecutable != NULL){
  fseek(ejecutable, 0, SEEK_END);
  tamanio = ftell(ejecutable);
  rewind(ejecutable);
  contenido_archivo = malloc(tamanio+1);
  fread(contenido_archivo, sizeof(char),tamanio, ejecutable);
  contenido_archivo[tamanio+1]='\0';
  fclose(ejecutable);
 }

 printf("%s\n", contenido_archivo);

 int tamanio_instruccion;
 int tamanio_sentencia;
 int i=0;
 int j=0;
 int puntero = 0;
 int cantidad_instrucciones=0;

 while(puntero < tamanio+1){
	if (contenido_archivo[puntero] == '\n'){
		cantidad_instrucciones ++;
	}
	puntero++;
 } //Saco la cantidad de instrucciones

 printf("Número de instrucciones %d\n", cantidad_instrucciones);
 //sleep(40);
 while(cantidad_instrucciones > 0){

	 if (j!=0){j++;}

	 tamanio_instruccion = tamanio_sentencia;

	 for (tamanio_sentencia = j; (contenido_archivo)[tamanio_sentencia] != '\n';tamanio_sentencia++);

	 tamanio_sentencia = tamanio_sentencia - tamanio_instruccion;

	 char * sentencia = malloc(tamanio_sentencia-1);

	 printf("tamanio de sentencia %d\n", tamanio_sentencia);

	 while(tamanio_sentencia >= j){

 		 if (contenido_archivo[j] != ' '){

			 sentencia[j]=contenido_archivo[j];}
		 else{
			printf("La sentencia es %s \n", sentencia);
			//logica según la sentencia
		 }
		 j++;
	 }
	 printf("La sentencia es %s \n", sentencia);


//for (tamanio_instruccion = 1; (sentencia)[tamanio_instruccion - 1] != ' ';
//		tamanio_instruccion++);

	 free (sentencia);
 	 cantidad_instrucciones = cantidad_instrucciones -1;
 	 }

}


int main(void) {
	archivo = "/home/utnso/workspace/prueba.txt";
	leerInstrucciones(archivo);
	return EXIT_SUCCESS;
}
