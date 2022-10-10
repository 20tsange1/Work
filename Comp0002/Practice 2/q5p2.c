#include "graphics.h"
#include <stdio.h>

int main(void) {
    for (int countery = 1; countery <= 6; countery++) {
        for (int counterx = 1; counterx <= 6; counterx++) {
            if (counterx >= countery) {
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