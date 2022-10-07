#include "graphics.h"
#define _USE_MATH_DEFINES // for C
#include <math.h>

int main(void)
{
 drawArc(150,50,200,200,0,360);
 drawLine(250+100*(sqrt(2)/2),150+100*(sqrt(2)/2),250-100*(sqrt(2)/2),150+100*(sqrt(2)/2));
 drawLine(250+100*(sqrt(2)/2),150-100*(sqrt(2)/2),250-100*(sqrt(2)/2),150-100*(sqrt(2)/2));
 drawLine(250+100*(sqrt(2)/2),150+100*(sqrt(2)/2),250+100*(sqrt(2)/2),150-100*(sqrt(2)/2));
 drawLine(250-100*(sqrt(2)/2),150+100*(sqrt(2)/2),250-100*(sqrt(2)/2),150-100*(sqrt(2)/2));
}