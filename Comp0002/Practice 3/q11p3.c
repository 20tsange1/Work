#include <stdio.h>
#include <string.h>
#include "graphics.h"

#define ScreenWidth 400
#define ScreenHeight 400

int main() {

    char pattern[] = "---+-+++-+---+-+++-+";

    setWindowSize(ScreenWidth,ScreenHeight);

    for (int x = 0; x < (ScreenWidth/20); x++) {
        for (int y = 0; y < (ScreenHeight/20); y++) {
            if (x == ( (0 + (3 * y)) % 20) || x == ((1 + (3 * y)) % 20) || x == ((2 + (3 * y)) % 20) || x == ((4 + (3 * y)) % 20) || x == ((8 + (3 * y)) % 20) || x == ((10 + (3 * y)) % 20) || x == ((11 + (3 * y)) % 20) || x == ((12 + (3 * y)) % 20) || x == ((14 + (3 * y)) % 20) || x == ((18 + (3 * y)) % 20) ) {
                setColour(blue);
            }   
            else {
                setColour(yellow);
            }
            fillRect(x*20, y*20, x*20+20, y*20+20);
        }
    }

}