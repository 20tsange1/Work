#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include <math.h>

int main() {

    setWindowSize(500, 500);
    // set background
    
   background();
    
    for(int y = 0; y <= 10; y++) {
        for(int x = 0; x <= 10; x++) {
            if ( (y % 2 == 0) && (x % 2 == 1) ) {
                setColour(black);
            }
            else if ( (y % 2 == 0) && (x % 2 == 0) ) {
                setColour(white);
            }
            else if ( (y % 2 == 1) && (x % 2 == 1) ) {
                setColour(white);
            }
            else if ( (y % 2 == 1) && (x % 2 == 0) ) {
                setColour(black);
            }

            fillRect(x*50, y*50, x*50 + 50, y*50 + 50);
        
        }
    }

    // set foreground

    foreground();

    int stop = 0;
    int x = 1;
    int y = 1;
    int xmulti = rand() % 10;
    int ymulti = rand() % 10;
    int xval = 1;
    int yval = 1;
    
    while (stop == 0) {
        setColour(red);
        sleep(10);
        clear();

        if (x >= 500) {
            xmulti = rand() % 10;
            xval = -1;
        }
        else if (x <= 0) {
            xmulti = rand() % 10;
            xval = 1;
        }

        if (y >= 500) {
            xmulti = rand() % 10;
            yval = -1;
        }
        else if (y <= 0) {
            xmulti = rand() % 10;
            yval = 1;
        }

        ymulti = sqrt(10*10 - xmulti*xmulti);

        x += xmulti * xval;
        y += ymulti * yval;

        fillOval(x,y,50,50);
    }
    
    

}