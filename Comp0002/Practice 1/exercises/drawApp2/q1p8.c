#include "graphics.h"

int main (void) {
    int i;

    for (i = 1; i < 20; ++i)
    drawOval(250-5*i, 150-5*i, 10*i, 10*i);
}