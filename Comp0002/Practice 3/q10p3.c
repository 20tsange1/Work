#include <stdio.h>

void big0(num)
{
    const char *zero[] = {" **** ", "*    *", "*    *", "*    *", " **** "};

    printf("%s", zero[num]);
}

void big1(num)
{
    const char *one[] = {" * ", "** ", " * ", " * ", "***"};

    printf("%s", one[num]);
}

void big2(num)
{
    const char *two[] = {"******", "     *", "******", "*     ", "******"};

    printf("%s", two[num]);
}

void big3(num)
{
    const char *three[] = {"******", "     *", "******", "     *", "******"};

    printf("%s", three[num]);
}

void big4(num)
{
    const char *four[] = {"   ** ", "  * * ", " *  * ", "******", "    * "};

    printf("%s", four[num]);
}

void big5(num)
{
    const char *five[] = {"******", "*     ", "******", "     *", "******"};

    printf("%s", five[num]);
}

void big6(num)
{
    const char *six[] = {"******", "*     ", "******", "*    *", "******"};

    printf("%s", six[num]);
}

void big7(num)
{
    const char *seven[] = {"******", "    * ", "   *  ", "  *   ", " *    "};

    printf("%s", seven[num]);
}

void big8(num)
{
    const char *eight[] = {" **** ", "*    *", " **** ", "*    *", " **** "};

    printf("%s", eight[num]);
}

void big9(num)
{
    const char *nine[] = {"******", "*    *", "******", "     *", "******"};

    printf("%s", nine[num]);
}

void bigmin(num)
{
    const char *minus[] = {"      ", "      ", "  --  ", "      ", "      "};

    printf("%s", minus[num]);
}

int main()
{
    char num[8];

    printf("Enter a number:");
    scanf("%s", num);
    int len = sizeof(num)/sizeof(char);

    for (int i = 0; i < 5; i++)
    {
        for (int c = 0; c < len; c++)
        {
            switch (num[c])
            {
            case '0':
                big0(i);
                break;

            case '1':
                big1(i);
                break;

            case '2':
                big2(i);
                break;

            case '3':
                big3(i);
                break;

            case '4':
                big4(i);
                break;

            case '5':
                big5(i);
                break;

            case '6':
                big6(i);
                break;

            case '7':
                big7(i);
                break;

            case '8':
                big8(i);
                break;

            case '9':
                big9(i);
                break;

            case '-':
                bigmin(i);
                break;
            }
            printf(" ");
        }
        printf("\n");
    }

    return -1;
}