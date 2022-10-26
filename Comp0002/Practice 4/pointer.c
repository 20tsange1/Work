#include <stdio.h>

int main() {
    int num = 15;
    int *location = &num;
    int *pointer = NULL;

    printf("%x\n", location);
    printf("%d\n", *location);

    return 0;
}