#include <stdio.h>

int multiply(start, end) {
    if (start < end) {
        return start * multiply(start+1, end);
    }
    return start;
}

int main() {
    int start, end, val;
    val = 1;
    printf("Enter two numbers for a range:");
    scanf("%i %i", &start, &end);
    printf("\nMultiplied = %d", multiply(start, end));
}