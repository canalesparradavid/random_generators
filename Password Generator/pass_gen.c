/*
 * FICHERO: pass_gen.c
 * DESCRIPCION:
 *      Este programa genera una contraseña de tamaño PASS_SIZE que combina
 *      carcacteres de todo tipo.
 *
 * HISTORICO:
 *      v1.0 Creado por David Canales el 13/05/2023
 *          Esta version genera una contraseña aleatoria a portir de un set
 *          de caracteres.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASS_SIZE 8

int main(int argc, char **argv) {
    char posibles_caracteres[] = "abcdefghijklmnopqrtsuvwxyzABCDEFGHIJKLMNOPQRTSUVWXYZ0123456789?!@#$%^&*()_-;:.,/";

    // Inicializo el generador de numeros aleatorios
	srand(time(NULL));

    // Genero la contraseña de tamaño PASS_SIZE
    for (int i = 0; i < PASS_SIZE; i++) {
        int r = rand() % strlen(posibles_caracteres);
        printf("%c", posibles_caracteres[r]);
    }

	// Espero a un input para cerrar el progama
	printf("\n\nPRESIONE ENTER PARA CERRAR EL PROGRAMA...");
	scanf("[^\n]");

	return 0;
}
