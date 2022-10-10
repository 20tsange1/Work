#include "graphics.h"
#include <stdio.h>

int main(void) {
    for (int counter = 1; counter < 13; counter++) {
        printf("%i * 13 = %i", counter, counter*13);
        printf("\n");
    }
    return 0;
}