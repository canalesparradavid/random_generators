/*
 * FICHERO: dice_throw.c
 * DESCRIPCION:
 *      Este programa simula el lanzamiento de un dado de N caras siendo N un numero
 *      introducido por el usuario por teclado.
 *
 * HISTORICO:
 *      v1.0 Creado por David Canales el 18/05/2023
 *          Esta version realiza un unico lanzamiento de un dado de N caras.
 */

#include <stdio.h>
#include "dado.h"

int main(int argc, char **argv) {
    int n;
    Dado dado;

    printf("¿Cuantas caras tiene el dado?");
    scanf("%d", &n);

    nuevoDado(&dado, n);

    printf("\nResultado: %d\n", tirarDado(&dado));

    return 0;
}
