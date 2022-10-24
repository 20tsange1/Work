#include <stdio.h>

int prime(num) {
    int counter = 0;
    for (int i = 1; i <= num/2; i++) {
        if (num % i == 0) {
            counter++;
        }
    }
    return counter;
}

int main() {
    long longint;

    printf("Enter a long integer:");
    if (scanf("%li", &longint) == 1) {
        int isPrime = prime(longint);
        if (isPrime == 1) {
            printf("\nPrime");
        }
        else {
            printf("\nNot Prime");
        }
        
    }
    else {
        printf("Not a long int.");
    }

    
}