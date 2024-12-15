#include <stdio.h>

union floatbitmap {
    float var;
    unsigned char vec[4];
    struct {
        unsigned int mantisa : 23;
        unsigned int exponente : 8;
        unsigned int signo : 1;
    } BITS;
};

int main() {
    union floatbitmap numero;
    int opcion;

    do {
        printf("\n\n1. Ingrese un numero\n");
        printf("2. Ver numero\n");
        printf("3. Salir del programa\n");
        printf("\n\nSeleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Por favor, ingrese un numero: ");
                scanf("%f", &numero.var);
                break;

            case 2:
                printf("El numero en la memoria esta guardado como: 0x");
                for (int i = 3; i >= 0; i--) {
                    printf("%02X", numero.vec[i]);
                }
                printf("\n");
                if (numero.BITS.signo == 0) {
                    printf("El signo es positivo\n");
                } else {
                    printf("El signo es negativo\n");
                }
                printf("La mantisa es 0x%06X\n", numero.BITS.mantisa);
                printf("El exponente es %d\n", numero.BITS.exponente - 127);
                printf("El numero ingresado fue %f\n", numero.var);
                break;

            case 3:
                printf("Programa cerrado\n");
                break;

            default:
                printf("Opcion invalida, ingrese 1, 2 o 3.\n");
                break;
        }
    } while (opcion != 3);

    return 0;
}
