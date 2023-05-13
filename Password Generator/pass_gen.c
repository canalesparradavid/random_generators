/*
 * FICHERO: pass_gen.c
 * DESCRIPCION:
 *      Este programa genera una contraseña de tamaño PASS_SIZE que combina
 *      carcacteres de todo tipo.
 *
 * HISTORICO:
 *      v2.0 Creado por David Canales el 13/05/2023
 *          Esta version genera una contraseña aleatoria a portir de un set
 *          de caracteres cargados desde un fichero de configuracion en caso
 *          de que este exista.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

typedef struct set {
    char *nombre;
    char *caracteres;
    int uso_minimo;
} Set;

typedef struct configuracion {
    int pass_size;
    int numero_sets;
    Set *sets;
} Configuracion;

/*
 * FUNCION: existeConfiguracion
 * ENTRADA: El nombre de un fichero de configuracion
 * SALIDA: Verdadero en casao de que el fichero exista y falso en otro caso
 */
bool existeConfiguracion(char *config_file);

/*
 * ACCION: cargarConfiguracion
 * ENTRADA: El nombre de un fichero de configuracion
 * MODIFICA: Almacena en una variable la configuracion de generacion
 */
void cargarConfiguracion(char *config_file, Configuracion *config);

/*
 * ACCION: crearSet
 * ENTRADA: Un set, un nombre, los caracteres que usa el set y el uso minimo del set
 * MODIFICA: Inicializa el set con los valores dados
 */
void crearSet(Set *set, char *nombre, char *caracteres, int uso_minimo);

/*
 * FUNCION: satisfacerRequisitos
 * ENTRADA: Una configuracion de generacion
 * SALIDA: Un string que satisface los requisitos de la contraseña
 */
char *satisfacerRequisitos(Configuracion config);

/*
 * FUNCION: shuffle
 * ENTRADA: Una string
 * SALIDA: Los caracteres de la string desordenados
 */
 char *shuffle(char *texto);

int main(int argc, char **argv) {
    Configuracion config;

    if(!existeConfiguracion("config.txt")) {
        // Reservo memoria para poder almacenar un set
        config.sets = malloc(sizeof(Set));

        // Almaceno los valores de la configuracion por defecto
        config.pass_size = 8;
        config.numero_sets = 1;
        crearSet(
            &config.sets[0],
            "default",
            "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRTSUVWXYZ0123456789",
            1
        );
    }
    else {

    }

    // Inicializo el generador de numeros aleatorios
	srand(time(NULL));

    // Genero la contraseña
    char *pseudo_contrasena = satisfacerRequisitos(config);
    printf("%s\n", pseudo_contrasena);
    printf("%s\n", shuffle(pseudo_contrasena));

	// Espero a un input para cerrar el progama
	printf("\nPRESIONE ENTER PARA CERRAR EL PROGRAMA...");
	scanf("[^\n]");

	return 0;
}

void crearSet(Set *set, char *nombre, char *caracteres, int uso_minimo) {
    // Reservo memoria para poder almacenar los valores dados
    set->nombre = malloc(sizeof(char) * (strlen(nombre) + 1));
    set->caracteres = malloc(sizeof(char) * (strlen(caracteres) + 1));

    // Almaceno los valores en el set
    strcpy(set->nombre, nombre);
    strcpy(set->caracteres, caracteres);
    set->uso_minimo = uso_minimo;
}

bool existeConfiguracion(char *config_file) {
    FILE *config_stream = fopen(config_file, "r");

    if (config_stream == NULL) {
        return false;
    }

    return true;
}

void cargarConfiguracion(char *config_file, Configuracion *config) {

}

char *satisfacerRequisitos(Configuracion config) {
    char *pseudo_contrasena = malloc(sizeof(char) * (config.pass_size + 1));

    int i = 0;
    for (int set_index = 0; set_index < config.numero_sets; set_index++) {
        Set *set = &(config.sets[set_index]);
        for (int indice_uso = 0; indice_uso < set->uso_minimo; indice_uso++) {
            int r = rand() % strlen(set->caracteres);
            pseudo_contrasena[i] = set->caracteres[r];
            i = i + 1;
        }
    }

    while (i < config.pass_size) {
        // Establezco de que set cogere el caracter
        int set_index = rand() % config.numero_sets;
        Set *set = &(config.sets[set_index]);

        // Cojo un carcater del set
        int r = rand() % strlen(set->caracteres);
        pseudo_contrasena[i] = set->caracteres[r];

        i = i + 1;
    }

    return pseudo_contrasena;
}

char *shuffle(char *texto) {
    char *aux = malloc(sizeof(char) * (strlen(texto) + 1));
    char *texto_desordenado = malloc(sizeof(char) * (strlen(texto) + 1));

    strcpy(aux, texto);
    for (int i = 0; i < strlen(texto); i++) {
        int r = rand() % strlen(aux);
        texto_desordenado[i] = aux[r];

        // Actualizo la string pero sin el caracter extraido
        aux[r] = '\0';
        strcat(aux, &aux[r+1]);
    }

    return texto_desordenado;
}
