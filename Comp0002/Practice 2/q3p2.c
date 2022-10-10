#include "graphics.h"
#include <stdio.h>

int main(void) {
    printf("Do While /n");
    int counter = 1;
    do {
        printf("%i * 13 = %i", counter, counter*13);
        printf("\n");
        counter++;
    } while(counter <= 13);
    return 0;
}