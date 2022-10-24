#include <stdio.h>

int reverse(num) {
    
}

int main() {
    int longint, reversed, size, sum, counter;
    printf("Enter a long int:");
    scanf("%d", &longint);
    int original = longint;
    
    reversed = 0;
    // go through each thing, %10 and then - remaining

    while (longint > 0) {
        reversed *= 10;
        reversed += longint % 10;
        longint /= 10;
    }

    if (reversed == original) {
        printf("\nPalindrome");
    }
    else {
        printf("\nNot Palindrome");
    }

}