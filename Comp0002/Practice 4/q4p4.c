#include <stdio.h>
#include <string.h>

int strend(char *s, char *t) {
    int lens = strlen(s);
    int lent = strlen(t);

    if (strstr(s, t) != NULL && strcmp(&s[lens - lent], &t) ) {
        return 1;
    }
    else {
        return 0;
    }

}

int main() {
    
    printf("%i", strend("Dumbluck", "luck"));

    return 0;
}