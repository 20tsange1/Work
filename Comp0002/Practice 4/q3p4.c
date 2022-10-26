#include <stdio.h>
#include <stdlib.h>

char* stringCopy(char *s) {
    char *copy;
    copy = (char*) malloc(sizeof(s));
    copy = s;
    printf("%x - %x\n", &copy, &s);
    return copy;
}

int main() {
    
    printf("%s", stringCopy("stupid"));

    return 0;
}