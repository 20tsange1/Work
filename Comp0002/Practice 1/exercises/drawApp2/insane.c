// Written by <put your name and current date here>
// This program displays my name.
#include <stdio.h>
#include <string.h>
int main(void)
{
 char myName[] = "Amazing Person #1";
 char name[] = "Dept. of Computer Science";
 char address1[] = "Malet Place Engineering Building";

 printf("Hello, my name is %s and I am in the %s at the %s\n", myName, name, address1);

 int index = strlen(myName) - 1;
 while (index > -1)
 {
 printf("%c", myName[index]);
 index = index - 1;
 }
 printf("\n");
 return 0;
}