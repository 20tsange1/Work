#include "graphics.h"
#include <stdio.h>

int main(void) {
    int val = 1;
    for (int countery = 1; countery <= 6; countery++) {
        for (int counterx = 1; counterx <= 6; counterx++) {
            if (countery % 2 == 0) {
                if (counterx % 2 == 0) {
                    printf("*");
                }
                else {
                    printf("#");
                }
            }
            else {
                if (counterx % 2 == 0) {
                    printf("#");
                }
                else {
                    printf("*");
                }
            }
        }
        printf("\n");
    }
    return 0;
}