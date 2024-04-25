#include <stdio.h>
union numeros{
    float var;
    unsigned char vect [4];
};
int main (void){
    union numeros numero;
    printf ("Ingrese un numero\n");
    scanf("%f", &numero.var);
    printf ("El numero esta guardado en la memoria como\n");
    for (int i=3; i>=0;i--){
        printf("%x",numero.vect[i]);
    }
}
