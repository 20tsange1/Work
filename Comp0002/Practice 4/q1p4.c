#include <stdio.h>
#include "graphics.h"

int main() {
    int stop = 1;
    int switchval = 0;
    int x = 175;
    int y = 195;


    while (stop == 1) {

        sleep(10);

        clear();

        setColour(green);
        fillArc(175,75, 150, 150, 0, 360);

        setColour(white);
        fillArc(200,100, 100, 100, 0, 360);

        switch (switchval % 4) {
            case 0:
                
                y--;
                if (y <= 75) {
                    switchval++;
                }

                break;

            case 1:
                
                x++;
                if (x >= 295) {
                    switchval++;
                }

                break;
            
            case 2:

                y++;
                if (y >= 195) {
                    switchval++;
                }

                break;
            
            case 3:

                x--;
                if (x <= 175) {
                    switchval++;
                }

                break;

        }

        setColour(blue);
        fillRect(x,y,30,30);
        
    }
    
    
}