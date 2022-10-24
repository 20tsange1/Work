#include <stdio.h>

int main() {
    int hours, minutes;
    printf("Enter a time:");
    scanf("%d:%d", &hours, &minutes);
    if (hours >= 12) {
        printf("\n%d.%dpm", hours, minutes);
    }
    else {
        printf("\n%d.%dam", hours, minutes);
    }
    
}