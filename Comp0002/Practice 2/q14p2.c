#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graphics.h"


int main(void) {
    char chr;
    int y;
    int x;
    printf("Enter a symbol: ");
    scanf("%c", &chr);
    printf("\nEnter y size: ");
    scanf("%i", &y);
    printf("\nEnter x size: ");
    scanf("%i", &x);


    for (int numy = 0; numy < y; numy++) {
        for (int numx = 0; numx < x; numx++) {
            printf("%c", chr);
        }
        printf("\n");
    }
}