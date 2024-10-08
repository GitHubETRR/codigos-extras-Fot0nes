#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LARGO 50
#define MAX_CANCIONES 20
#define CARGAR 1
#define IMPRIMIR 2
#define SALIR 3

typedef struct Cantante {
    char nombre[MAX_LARGO];
    int escenario;
    char canciones[MAX_CANCIONES][MAX_LARGO];
    int numCanciones;
    struct Cantante* siguiente;
} Cantante;

void menu();
void crear_artista();
void pedir_datos(Cantante* cantante);
void liberar_memoria();
void escribir_archivo();

Cantante* cantantes = NULL;

int main() {
    menu();
    liberar_memoria();
    return 0;
}

void menu() {
    int opcion;
    do {
        printf("\n1_Cargar un artista/banda\n2_Imprimir lista\n3_Salir\n");
        scanf("%d", &opcion);
        while (opcion != CARGAR && opcion != IMPRIMIR && opcion != SALIR) {
            printf("Error. Volver a ingresar: ");
            scanf("%d", &opcion);
        }
        if (opcion == CARGAR) {
            crear_artista();
        } else if (opcion == IMPRIMIR) {
         escribir_archivo; 
         printf("Información de cantantes escrita en cantantes.txt\n");
        }
    } while (opcion != SALIR);
}

void crear_artista() {
    Cantante *cantante_aux = malloc(sizeof(Cantante));
    if (cantante_aux == NULL) {
        printf("Sin memoria\n");
    } else {
        pedir_datos(cantante_aux);
        cantante_aux->siguiente = cantantes;
        cantantes = cantante_aux;
    }
}

void pedir_datos(Cantante* cantante) {
    printf("\nIngrese el nombre del cantante/banda: ");
    scanf(" %[^\n]%*c", cantante->nombre);

    printf("Ingrese el número del escenario: ");
    scanf("%d", &cantante->escenario);

    printf("Ingrese la cantidad de canciones que va a tocar (máximo %d): ", MAX_CANCIONES);
    scanf("%d", &cantante->numCanciones);

    if (cantante->numCanciones > MAX_CANCIONES) {
        printf("Se excedio el número máximo de canciones\n");
        return;
    }

    printf("Ingrese las canciones:\n");
    for (int j = 0; j < cantante->numCanciones; j++) {
        printf("Canción %d: ", j + 1);
        scanf(" %[^\n]%*c", cantante->canciones[j]);
    }
}


void escribir_archivo() {
    FILE *archivo = fopen("cantantes.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "\nInformación de Cantantes\n");
   
    Cantante* lista = cantantes;
    int numCantantes = 0;
    while (lista != NULL) {
        numCantantes++;
        lista = lista->siguiente;
    }
    lista = cantantes;
    for (int i = 0; i < numCantantes; i++) {
        fprintf(archivo, "Cantante %d\n", i + 1);
        fprintf(archivo, "Nombre: %s\n", lista->nombre);
        fprintf(archivo, "Escenario: %d\n", lista->escenario);
        fprintf(archivo, "Canciones:\n");
        for (int j = 0; j < lista->numCanciones; j++) {
            fprintf(archivo, "  %d. %s\n", j + 1, lista->canciones[j]);
        }
        fprintf(archivo, "\n");
        lista = lista->siguiente;
    }

    if (fclose(archivo) != 0) {
        printf("Error al cerrar el archivo.\n");
        return;
    }
}

void liberar_memoria() {
    Cantante* liberar;
    while (cantantes != NULL) {
        liberar = cantantes;
        cantantes = cantantes->siguiente;
        free(liberar);
    }
}