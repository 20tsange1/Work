#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    printf("Enter 3 sides, a, b and c:");
    scanf("%d %d %d", &a, &b, &c);

    if ( (a + b > c ) || (a + c > b) || (b + c > a) ) {
        double area, peri;
        peri = a + b +c;
        area = sqrt((peri/2)*(peri/2 - a)*(peri/2 - b)*(peri/2 - c));
        printf("\nValid, Area = %lf, Perimeter = %lf", area, peri);
    }
    else {
        printf("\nInvalid");
    }
}
