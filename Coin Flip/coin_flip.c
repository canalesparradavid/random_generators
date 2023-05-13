#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
	// Inicializo el generador de numeros aleatorios
	srand(time(NULL));

	// Genero un numero aletorio entre
	int r = rand() % 2;

	if (r == 0) {
		printf("CARA\n");
	}
	else {
		printf("CRUZ\n");
	}

	// Espero a un input para cerrar el progama
	printf("\nPRESIONE ENTER PARA CERRAR EL PROGRAMA...");
	scanf("[^\n]");

	return 0;
}
