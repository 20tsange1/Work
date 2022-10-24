#include <stdio.h>

int power(num, pow) {
    int base = 1;
    for (int i = 0; i < pow; i++) {
        base = base * num;
    }
    return base;
}

int powerrec(num, pow) {
    if (pow > 1) {
        num = num * powerrec(num,pow-1);
    }
    return num;
}

int main() {
    int num, pow;
    printf("Enter a number and the power:");
    scanf("%d %d", &num, &pow);

    printf("Loop = %d\n", power(num, pow));
    printf("Recursive = %d\n", powerrec(num, pow));

    return 0;
}