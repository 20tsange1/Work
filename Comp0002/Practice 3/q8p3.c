#include <stdio.h>

int factorial(num)
{
    int fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }
    return fact;
}

int strong(num)
{

    int each = 0;
    int sum = 0;
    int numcheck = num;
    // go through each thing, %10 and then - remaining

    while (numcheck > 0)
    {
        each = numcheck % 10;

        sum += factorial(each);

        numcheck = (numcheck - (numcheck % 10)) / 10;
    }

    if (sum == num)
    {
        return 1;
    }
    else
    {
        return -1;
    }
    return -1;
}

int main()
{
    int num, end;

    printf("Enter a range (a b):");
    scanf("%i %i", &num, &end);

    for (int i = num; i <= end; i++)
    {
        if (strong(i) == 1)
        {
            printf("\n%i = Strong", i);
        }
    }
}