// Use a 2D array for the maze.
// Make the robot consider both sides and record down how many steps.

#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"

#define CanvasWidth 480
#define CanvasHeight 480


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

void generateMaze(int maze[12][12], int mazeStartEnd[4]) {

    //make maze using probablistic approach, skewed to generate longer lines

    for (int y = 0; y < 12; y++) {
        for (int x = 0; x < 12; x++) {
            if (rand() % 10 <= 4) {
                maze[y][x] = 1;
            }
            else {
                maze[y][x] = 0;
            }

            // saying that the maze ends there
            if (x == 11) {
                mazeStartEnd[2] = x;
                mazeStartEnd[3] = y;
                break;
            }
        }
    }

    mazeStartEnd[0] = 0;
    mazeStartEnd[1] = 1;


}

void drawRobot(int x, int y, int direction) {
    foreground();
    setColour(blue);
    for (int i = 0; i < 40; i++) {
        sleep(10);
        clear();

        switch (direction) {

            case (-1):
                fillArc(x * 40 + 5, y * 40 + 5, 30, 30, 0, 360);
                break;

            case (1):
                fillArc(x * 40 + 5, (y-1) * 40 + 5 + i, 30, 30, 0, 360);
                break;

            case (2):
                fillArc(x * 40 + 5, (y+1) * 40 + 5 + i, 30, 30, 0, 360);
                break;

            case (3):
                fillArc((x-1) * 40 + 5 + i, y * 40 + 5, 30, 30, 0, 360);
                break;

            case (4):
                fillArc((x+1) * 40 + 5 + i, y * 40 + 5, 30, 30, 0, 360);
                break;

        }
    }
    
}

void endFound() {
    clear();
    background();
    clear();

    setColour(black);
    fillRect(0, 0, CanvasWidth, CanvasHeight);

    foreground();
    setColour(white);
    drawString("Robot has solved the maze", 150, 240);

}

// Example basic maze ( 0 = black 1 = white)
//int maze[12][12] = { {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} , {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1} };



// Robot should only be able to see in 4 directions, hence see maze[i][i], maze[i+1][i], maze[i-1][i], maze[i][i+1], maze[i][i-1]

int main() {

    setWindowSize(CanvasWidth,CanvasHeight);

    int maze[12][12] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} , {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };
    // Array containing start and end of maze
    int mazeStartEnd[4];

    //int maze[12][12];

    //generateMaze(maze, mazeStartEnd);

    drawMaze(maze);

    int robotX = 0;
    int robotY = 1;

    int lastRobotX = 0;
    int lastRobotY = 0;

    int direction = -1; // Up = 1 Down = 2 Right = 3 Left = 4

    while ( (robotY != mazeStartEnd[2]) || (robotX != mazeStartEnd[3]) ) {
        drawRobot(robotX, robotY, direction);

        // Condition should be so that it moves in a new direction continously.

        if ( (maze[robotY + 1][robotX] == 1) && ( (( robotY + 1 ) != lastRobotY) && ( robotX != lastRobotX) ) ) {
            robotY += 1;

            lastRobotY = robotY - 1;

            direction = 1;
        }

        else if ( (maze[robotY - 1][robotX] == 1) && ( ( ( robotY - 1 ) != lastRobotY) && ( robotX != lastRobotX) ) ) {
            robotY -= 1;
             
            lastRobotY = robotY + 1;

            direction = 2;
        }

        else if ( (maze[robotY][robotX + 1] == 1) && ( ( ( robotX + 1 ) != lastRobotX) && ( robotY != lastRobotY) ) ) {
            robotX += 1;

            lastRobotX = robotX - 1;

            direction = 3;
        }

        else if ( (maze[robotY][robotX - 1] == 1) && ( ( ( robotX - 1 ) != lastRobotX) && ( robotY != lastRobotY) ) ) {
            robotX -= 1;

            lastRobotX = robotX + 1;

            direction = 4;
        }


        
        printf("%i, %i\n", robotX, robotY);

    }


    // end sequence as loop ends when maze end is found but not travelled to.
    drawRobot(robotX, robotY, direction);
    direction = -1;
    drawRobot(robotX, robotY, direction);

    endFound();


    return 0;
}