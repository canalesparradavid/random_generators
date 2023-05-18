/*
 * MODULO: Dado
 * FICHERO: dado.c
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

#include "dado.h"

int DADOS_SRAND_INITIALIZED = 0;        //Lo uso para inicializar el srand una unica vez

/*
 * ACCION: nuevoDado
 * ENTRADA: Un dado y un numero de caras
 * MODIFICA: Inicializa el dado
 */
void nuevoDado(Dado *d, int nCaras){
    //Inicializo los datos del dado
    d->nCaras = nCaras;
    d->resultado = 0;

    //Inicializo los datos de las estadisticas
    d->estadisticas.repeticionesResultado = malloc(sizeof(int) * nCaras);
    d->estadisticas.media = 0;
    d->estadisticas.nTiros = 0;

    //Inicializo el generador aleatorios
    if(DADOS_SRAND_INITIALIZED != 1){
        srand(time(NULL));
        DADOS_SRAND_INITIALIZED = 1;
    }
}

/*
 * FUNCION: tirarDado
 * ENTRADA: Un dado
 * SALIDA: El resultado de tirar el dado
 */
int tirarDado(Dado *d){
    //Genero el nuevo numero y lo asigno
    //d->resultado = rand()%d->nCaras + 1;
    float r = (float)rand() / RAND_MAX;
    d->resultado = r*d->nCaras + 1;

    //Actualizo las estadistica
    float sumaParcialAnterior = d->estadisticas.media * d->estadisticas.nTiros;
    d->estadisticas.nTiros++;                                       //Actualizo el numero de tiros
    d->estadisticas.repeticionesResultado[d->resultado-1]++;        //Actualizo las repeticiones
    //Actualizo la media
    d->estadisticas.media = (sumaParcialAnterior + d->resultado) / d->estadisticas.nTiros;

    return d->resultado;
}

/*
 * ACCION: mostrarEstadisticas
 * ENTRADA: Un dado
 * SALIDA: Muestra por pantalla las estadisticas
 */
void mostrarEstadisticas(Dado d){
    printf("Numero de tiros: %d.\n", d.estadisticas.nTiros);
    printf("Media de todos los tiros: %fd.\n", d.estadisticas.media);
    printf("Repeticion de valores:\n");
    for(int i = 0; i < d.nCaras; i++)
        printf("\tNumero %d: %d\n", i+1, d.estadisticas.repeticionesResultado[i]);
}

/*
 * FUNCION: devolverMediaTiros
 * ENTRADA: Un dado
 * SALIDA: La media de los tiros realizados
 */
float devolverMediaTiros(Dado d){
    return d.estadisticas.media;
}

/*
 * FUNCION: devolverNumeroTiros
 * ENTRADA: Un dado
 * SALIDA: El numero de tiradas que se han realizado
 */
int devolverNumeroTiros(Dado d){
    return d.estadisticas.nTiros;
}

/*
 * FUNCION: devolverNumeroRepeticiones
 * ENTRADA: Un dado y un numero de 1 a nCaras
 * SALIDA: El numero de veces que ha salido el numero especificado
 */
int devolverNumeroRepeticiones(Dado d, int n){
    if(n > 0 && n <= d.nCaras){         //Si n es una cara valida
        return d.estadisticas.repeticionesResultado[n-1];
    }
    else
        return 0;
}
