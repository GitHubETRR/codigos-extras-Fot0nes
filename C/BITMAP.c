
#include <stdio.h>
#define BITS 4
struct BITMAP {
        unsigned value :3 ;
} bit[BITS];

int main(){

        bit[0].value = 4;
        bit[1].value = 1;
        bit[2].value = 2;
        bit[3].value = 3;
        int i;
        printf ("Escriba que valor quiere ver\n");
        scanf("%d", &i);
        printf("El valor del bit %i es %u\n", i, bit[i].value);
        
}
 