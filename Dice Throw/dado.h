/*
 * MODULO: Dado
 * FICHERO: dado.h
 * DESCRIPCION: Este modulo implementa la tipologia y funcionalidad necesarias
 *              para crear y usar un dado y almacenar sus estadisticas.
 *
 * HISTORICO:
 *              v1.0 Creado el 22/04/2021 por David Canales Parra
 *                  - Ceado el tipo Dado
 *                  - Ceado el tipo EstadisticasDado
 *                  - Ceado funcionalidad basica para usar dado aleatorio
 *                  - Ceado funcionalidad basica para mostrar las estadisticas del dado
 */

#ifndef HHH_DADO_DCP
#define HHH_DADO_DCP

//Importaciones
#include <stdio.h>      //Funcionalidad I/O
#include <time.h>       //Funcionalidad para hora
#include <stdlib.h>     //Funcionalidad para numeros aleatorios

//Exportaciones
typedef struct estadisticasdado{
    int *repeticionesResultado;
    float media;
    int nTiros;
} EstadisticasDado;

typedef struct dado{
    int nCaras;
    int resultado;
    EstadisticasDado estadisticas;
} Dado;

/*
 * ACCION: nuevoDado
 * ENTRADA: Un dado y un numeor de caras
 * MODIFICA: Inicializa el dado
 */
void nuevoDado(Dado *, int );

/*
 * FUNCION: tirarDado
 * ENTRADA: Un dado
 * SALIDA: El resultado de tirar el dado
 */
int tirarDado(Dado *);

/*
 * ACCION: mostrarEstadisticas
 * ENTRADA: Un dado
 * SALIDA: Muestra por pantalla las estadisticas
 */
void mostrarEstadisticas(Dado );

/*
 * FUNCION: devolverMediaTiros
 * ENTRADA: Un dado
 * SALIDA: La media de los tiros realizados
 */
float devolverMediaTiros(Dado );

/*
 * FUNCION: devolverNumeroTiros
 * ENTRADA: Un dado
 * SALIDA: El numero de tiradas que se han realizado
 */
int devolverNumeroTiros(Dado );

/*
 * FUNCION: devolverNumeroRepeticiones
 * ENTRADA: Un dado y un numero de 1 a nCaras
 * SALIDA: El numero de veces que ha salido el numero especificado
 */
int devolverNumeroRepeticiones(Dado , int );

#endif
