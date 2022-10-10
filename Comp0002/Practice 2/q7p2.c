#include "graphics.h"
#include <stdio.h>

int main(void) {
    for (int countery = 1; countery <= 7; countery++) {
        for (int counterx = 1; counterx <= 8; counterx++) {
            if (!(((2 <= counterx) && (counterx <= 7)) && ((2 <= countery) && (countery <= 6)))) {
                printf("*");
            }
            else {
                if ((!(((4 <= counterx) && (counterx <= 5)) && ((4 <= countery) && (countery <= 4)))) && ((counterx > 2 && counterx < 7) && (countery > 2 && countery < 6))) {
                    printf("#");
                }
                else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}