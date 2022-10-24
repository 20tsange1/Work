#include <stdio.h>

int main() {
    int num;
    const char *numbers[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const char *tees[9] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    const char *tens[9] = {"ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    printf("Enter a number between 0 and 999:");
    scanf("%d", &num);

    int counter = 100;

    if (num > 100) {
        printf("%s", numbers[(num - (num % 100)) / 100 - 1]);
        printf(" hundred and ");
    }
    
    if (num % 100 > 10 && num % 100 < 20) {
        printf ("%s", tees[(num % 100 - 10) - 1]);
    }
    if (num % 100 >= 20) {
        printf ("%s ", tens[ (( (num % 100 - ((num % 100) % 10))) / 10) - 1 ]);
        if (num % 10 > 0) {
            printf ("%s", numbers[ (num % 10) - 1]);
        }
    }
    
    
}