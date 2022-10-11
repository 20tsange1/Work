#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graphics.h"


int main(void) {
    int lasty = 150;
    int lastx = 250;
    for (float y = 0; y < 157; y = y + 0.01) {
            drawLine(250+sin(y)*y,150+cos(y)*y,250+sin(y)*y,150+cos(y)*y);
            }
    return 0;
}