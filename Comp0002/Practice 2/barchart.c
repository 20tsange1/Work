#include "graphics.h"

int main(void) {
    int i;

    for (i = 1; i < 8; ++i) {
        drawRect(100,20*i,200,20*i+10);
    }
        
}