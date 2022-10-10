#include "graphics.h"
#include <stdio.h>

int main(void) {
    for (int countery = 1; countery <= 9; countery++) {
        for (int counter = 1; counter <= 5; counter++) {
            if (counter < countery && countery <= 5) {
                printf(" ");
            }
            if (counter < 10-countery && countery > 5) {
                printf(" ");
            }
        }
        for (int counterx = 1; counterx <= 5; counterx++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}