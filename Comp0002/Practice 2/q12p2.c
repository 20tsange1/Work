#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graphics.h"


int main(void) {
    drawLine(0,150,500,150);
    drawLine(250,0,250,300);

    float lastx = 250-3.14*50;
    float lastysin = 150;
    float lastycos = 250;
    float lastytan = 0;
    for (float x = -3.14; x < 3.14; x = x+0.01) {
        drawLine(250+lastx*50,lastysin,250+x*50,150-sin(x)*100);
        lastysin = 150-sin(x)*100;
        drawLine(250+lastx*50,lastycos,250+x*50,150-cos(x)*100);
        lastycos = 150-cos(x)*100;
        if (tan(x) <= 1 && tan(x) >= -1) {  
            drawLine(250+lastx*50,lastytan,250+x*50,150-tan(x)*100);
            lastytan=150-tan(x)*100;
        }
        lastx = x;
    }


    return 0;
}