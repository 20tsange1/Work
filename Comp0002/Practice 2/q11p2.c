#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    for (int countery = 1; countery <= 100; countery++) {
        printf("%i\n", countery*countery);
    }
    for (int counter = 2; counter < 101; counter = counter + 2) {
        printf("%i\n", counter*counter);
    }
    
    int primes[100] = {};
    int count = 1;
    primes[0] = 1;
    for (int y = 2; y < 100; y++) {
        int l = 0;
        for (int x = 0; x < count; x++) {
            printf("%i", y % primes[x]);
            if (y % primes[x] == 0) {
                l++;
            }
        }
        if (l == 1) {
            count++;
            primes[count] = y;
        }
    }
    for (int x = 0; x < count; x++) {
        printf("%i\n", primes[x]);
    }   
        



    return 0;
}