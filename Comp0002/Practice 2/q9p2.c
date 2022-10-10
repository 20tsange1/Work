#include "graphics.h"
#include <stdio.h>

int main(void) {
    for (int countery = 1; countery <= 9; countery++) {
        for (int counterx = 1; counterx <= 5; counterx++) {
            if (counterx == 1 || counterx == countery || 10-counterx == countery) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}