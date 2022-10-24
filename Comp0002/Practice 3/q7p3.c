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
    int lastprime = -1; 
    int a, b;

    printf("Enter a range (a b):");
    scanf("%i %i", &a, &b);
    for (int i = a; i <= b; i++) {
        
        if (prime(i) == 1) {
            if (0 < (i - lastprime) && (i - lastprime) <= 2) {
                printf("%i and %i \n", lastprime, i);
            }
            lastprime = i;

        }
        
            
    }
}