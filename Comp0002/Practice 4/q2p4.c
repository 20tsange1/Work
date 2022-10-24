#include <stdio.h>
#include "graphics.h"

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

}