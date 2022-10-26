// Use a 2D array for the maze.
// Make the robot consider both sides and record down how many steps.

#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"


void drawMaze(int maze[12][12]) {
    background();
    setColour(black);

    for (int y = 0; y < 12; y++) {
        for (int x = 0; x < 12; x++) {

            if (maze[y][x] == 1) {
                setColour(white);
            }
            else {
                setColour(black);   
            }
            fillRect(x*40, y*40, x*40 + 40, y*40 + 40);
            setColour(black);
            drawRect(x*40, y*40, x*40 + 40, y*40 + 40);
            
        }
    }
}

void generateMaze(int maze[12][12]) {

    //make maze using probablistic approach, skewed to generate longer lines

    for (int y = 0; y < 12; y++) {
        for (int x = 0; x < 12; x++) {
            if (rand() % 10 <= 4) {
                maze[y][x] = 1;
            }
            else {
                maze[y][x] = 0;
            }
        }
    }
}

void drawRobot(int x, int y) {
    foreground();
    clear();
    setColour(blue);
    fillArc(x*40 + 5, y*40 + 5, 30, 30, 0, 360);
}

// Example basic maze ( 0 = black 1 = white)
//int maze[12][12] = { {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} , {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1} };



// Robot should only be able to see in 4 directions, hence see maze[i][i], maze[i+1][i], maze[i-1][i], maze[i][i+1], maze[i][i-1]

int main() {

    setWindowSize(480,480);

    int maze[12][12] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} , {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

    //int maze[12][12];

    //generateMaze(maze);

    drawMaze(maze);

    int robotX = 0;
    int robotY = 1;

    int lastRobotX = 0;
    int lastRobotY = 0;

    while ( (robotY != 12) || (robotX != 0) ) {
        sleep(100);
        drawRobot(robotX, robotY);

        // Condition should be so that it moves in a new direction continously.

        if ( (maze[robotY + 1][robotX] == 1) && ( (( robotY + 1 ) != lastRobotY) && ( robotX != lastRobotX) ) ) {
            robotY += 1;

            lastRobotY = robotY - 1;
        }

        else if ( (maze[robotY - 1][robotX] == 1) && ( ( ( robotY - 1 ) != lastRobotY) && ( robotX != lastRobotX) ) ) {
            robotY -= 1;
             
            lastRobotY = robotY + 1;
        }

        else if ( (maze[robotY][robotX + 1] == 1) && ( ( ( robotX + 1 ) != lastRobotX) && ( robotY != lastRobotY) ) ) {
            robotX += 1;
            lastRobotX = robotX - 1;
        }

        else if ( (maze[robotY][robotX - 1] == 1) && ( ( ( robotX - 1 ) != lastRobotX) && ( robotY != lastRobotY) ) ) {
            robotX -= 1;
            lastRobotX = robotX + 1;
        }

        


    }

    return 0;
}