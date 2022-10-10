#include "graphics.h"
#include <stdio.h>

int main(void) {
    for (int countery = 1; countery <= 8; countery++) {
        for (int counterx = 1; counterx <= 7; counterx++) {
            if (countery == 8) {
                printf("#");
            }
            else if (countery == 1) {
                printf("*");
            }
            else if ((countery > 1 && countery < 8) && ((counterx == 1) || (counterx == countery-1))) {
                printf("#");
            }
            else if ((countery > 1 && countery < 8) && ((counterx == 7) || (counterx == countery))) {
                printf("*");
            }
            else {
                if ((counterx >= 2 && counterx <= 7) && (countery != 1 || countery !=8)) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}