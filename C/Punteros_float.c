#include <stdio.h>

typedef union numero{
    float flotante;
    unsigned char caracter;
}numero;

int main(void){
    numero num;
    printf("\n Ingrese el valor del numero\n ");
    scanf("%f", &num.flotante);

    unsigned char *puntero = &num.caracter;
    printf("\nEl float se guardo en la memoria como: 0x");
    for(int i=3; i>=0; i--){
        printf("%02X", *(puntero+i));
    }
}