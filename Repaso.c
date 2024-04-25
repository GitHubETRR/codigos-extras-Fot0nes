#include <stdio.h>
#define LONG_NAME 30
#define CANT_EMPLOYEES 5

typedef struct empleado{
     char nombre[LONG_NAME];
     char edad;
     float salario;
} formato;

void Bienvenida (formato[]);
void ingresarDatos(formato[], int);
void procesarDatos(formato[], int);
void mostrarDatos(formato[], int);

int main (void){
    formato empleado[CANT_EMPLOYEES];
    Bienvenida(empleado);
}
void Bienvenida (formato empleado[]){
    int eleccion, empleados;
    printf("\n-----Menu-----\n\n");
    do{
        printf("1. Ingreso de datos de un empleado.\n");
        printf("2. Mostrar informacion ingresada.\n");
        printf("3. Salir.\n");
        do{
            printf("ingrese su opcion: ");
            scanf("%i", &eleccion);
            if (eleccion != 1 && eleccion != 2 && eleccion != 3){
            printf("Ha ingresado un numero invalido");
                }
        }while (eleccion != 1 && eleccion != 2 && eleccion != 3);

            switch (eleccion){
                case 1:
                printf("\nCuantos empleados va a ingresar\n");
                do{
                printf("Cantidad de empleados a ingresar: ");
                scanf("%i", &empleados);
                if (empleados > CANT_EMPLOYEES && empleados < 0){
                    printf("Cantidad invalida. Por favor, ingrese un valor entre 1 y 5.\n");
                }
                } while (empleados > CANT_EMPLOYEES && empleados < 0);
                ingresarDatos(empleado, empleados);
                break;
                case 2:
                procesarDatos(empleado, empleados);
                mostrarDatos(empleado, empleados);
                break;
        }
    } while (eleccion != 3);
} 




void ingresarDatos(formato empleado [], int empleados){
    for (int i = 0; i < empleados; i++){
        printf("Empleado N%c %i.\n", 167, i+1);
        printf("Nombre del empleado: ");
        scanf("\n%[^\n]s", &empleado[i].nombre);
        do{
            printf("Edad del empleado: ");
            scanf("%i", &empleado[i].edad);
            if (empleado[i].edad < 0){
                printf("Se debe ingresar una edad con un valor mayor a cero. Por favor, vuelva a ingresarlo.\n");
            }      
        } while (empleado[i].edad < 0);
        do{
            printf("Salario del empleado (en dolares): ");
            scanf("%f", &empleado[i].salario);
            if (empleado[i].salario < 1){
                printf("Se debe ingresar un salario con un valor mayor a uno. Por favor, vuelva a ingresarlo.\n");
            } 
        } while ((empleado[i].salario < 1));
        printf("\n");
    }
    printf("\nDatos ingresados de forma correcta.\n");
}


void procesarDatos(formato empleado[], int empleados){
    float prom = 0;
    int mayor = 0;
    for (int i = 0; i < empleados; i++){
        prom += empleado[i].salario;
        if(empleado[i].salario > empleado[mayor].salario){
            mayor=i;
        }
    }
    prom /= empleados;
    printf("\nEl promedio de salarios es de: %f\n", prom);
    printf("El empleado con el mayor salario es: %s, con un valor de %f\n", empleado[mayor].nombre, empleado[mayor].salario);
    }


void mostrarDatos(formato empleado[], int empleados){
    for (int i = 0; i < empleados; i++){
        printf("Empleado %d: Nombre: %s, edad: %i, salario: %c%f\n", i + 1, empleado[i].nombre, empleado[i].edad, 36, empleado[i].salario);
    }
}

