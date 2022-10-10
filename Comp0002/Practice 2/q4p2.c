#include "graphics.h"
#include <stdio.h>

int main(void) {
    for (int countery = 1; countery < 5; countery++) {
        for (int counterx = 1; counterx < 6; counterx++) {
            if (!(((2 <= counterx) && (counterx <= 4)) && ((2 <= countery) && (countery <= 3)))) {
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