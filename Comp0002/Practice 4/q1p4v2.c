#include <stdio.h>
#include "graphics.h"
#include <math.h>

int main() {
    int stop = 1;
    int xbase = 250-15;
    int ybase = 150-15;
    double x, y;
    double pi = 3.1415;
    double angle = 0;
    

    background();
    setColour(green);
    fillArc(175,75, 150, 150, 0, 360);

    setColour(white);
    fillArc(200,100, 100, 100, 0, 360);

    foreground();
    setColour(blue);

    while (angle != -1) {
        
        x = xbase + cos(angle / 180 * pi) * 60;
        y = ybase + sin(angle / 180 * pi) * 60;

        sleep(10);

        clear();

        fillRect(x, y, 30,30);
        
        angle++;

    }
}