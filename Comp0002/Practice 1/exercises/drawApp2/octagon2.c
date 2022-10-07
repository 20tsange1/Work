#include "graphics.h"
#define _USE_MATH_DEFINES // for C
#include <math.h>

int main(void)
{
 drawLine(0,150,250,150);
 drawLine(sin(M_PI/7)*100,150,250,150);
 return 0;
}