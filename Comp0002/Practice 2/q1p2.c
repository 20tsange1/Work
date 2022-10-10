#include "graphics.h"
#include <stdio.h>

int main(void) {
    int counter = 1;
    int val = 0;
    while (counter < 13) {
        val = counter * 13;
        printf("%i", counter);
        printf(" * 13 = ");
        printf("%i", val);
        printf("\n");
        counter++;
    }
    return 0;
}