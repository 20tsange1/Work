// Use a 2D array for the maze.
// Make the robot consider both sides and record down how many steps.

#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include <time.h>

#define CanvasWidth 680
#define CanvasHeight 680

void drawMaze(int maze[17][17])
{
    background();
    setColour(black);

    for (int y = 0; y < 17; y++)
    {
        for (int x = 0; x < 17; x++)
        {

            if (maze[y][x] == 1)
            {
                setColour(white);
            }
            else
            {
                setColour(black);
            }
            fillRect(x * 40, y * 40, x * 40 + 40, y * 40 + 40);
            setColour(black);
            drawRect(x * 40, y * 40, x * 40 + 40, y * 40 + 40);
        }
    }
}

void resetMaze(int maze[17][17])
{

    for (int y = 0; y < 17; y++)
    {
        for (int x = 0; x < 17; x++)
        {
            maze[y][x] = 0;
        }
    }
}

void createExit(int maze[17][17])
{
    for (int i = 16; i > 1; i--)
    {
        if (maze[i][15] == 1)
        {
            maze[i][16] = 1;
            break;
        }
    }
}

int mazeTouched(int mazeTouch[17][17])
{
    for (int y = 0; y < 17; y++)
    {
        for (int x = 0; x < 17; x++)
        {
            if (mazeTouch[y][x] == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

void generateMaze(int maze[17][17], int mazeTouch[17][17], int mazeStartEnd[4], int currentX, int currentY, int prevOrientation)
{
    int direction;

    // make maze using probablistic approach, skewed to generate longer lines

    // add so that it can be generated on the left too. (if all 4 sides empty, extend)
    // add so that it can extend in any direction from 1 to some n length (Needs to include going left and going up)

    int success = 1;
    int dire = rand() % 4;

    for (int i = 0; i < 4; i++)
    {
        direction = (dire + i) % 4;
        if (direction != prevOrientation)
        {

            printf("%i\n", direction);
            switch (direction)
            {

            // left
            case (0):
                if ( ((currentX - 2 > 0) && (currentX - 1 > 0) && (maze[currentY][currentX - 3] == 0)) && ((maze[currentY + 1][currentX - 2] == 0) && (maze[currentY - 1][currentX - 2] == 0)) && ((maze[currentY + 1][currentX - 1] == 0) && (maze[currentY - 1][currentX - 1] == 0)))
                {
                    maze[currentY][currentX - 1] = 1;
                    maze[currentY][currentX - 2] = 1;

                    generateMaze(maze, mazeTouch, mazeStartEnd, currentX - 1, currentY, 1);
                }
                break;

            // right
            case (1):
                if ( ((currentX + 2 < 16) && (currentX + 1 < 16) && (maze[currentY][currentX + 3] == 0)) && ((maze[currentY + 1][currentX + 1] == 0) && (maze[currentY - 1][currentX + 1] == 0)) && ((maze[currentY + 1][currentX + 2] == 0) && (maze[currentY - 1][currentX + 2] == 0)))
                {
                    maze[currentY][currentX + 1] = 1;
                    maze[currentY][currentX + 2] = 1;                    
                    generateMaze(maze, mazeTouch, mazeStartEnd, currentX + 1, currentY, 0);
                }
                break;

            // up
            case (2):
                if ( ((currentY - 1 > 0) && (currentY - 2 > 0) && (maze[currentY - 3][currentX] == 0)) && ((maze[currentY - 1][currentX + 1] == 0) && (maze[currentY - 1][currentX - 1] == 0)) && ((maze[currentY - 2][currentX + 1] == 0) && (maze[currentY - 2][currentX - 1] == 0)))
                {
                    maze[currentY - 1][currentX] = 1;
                    maze[currentY - 2][currentX] = 1;
                    
                    generateMaze(maze, mazeTouch, mazeStartEnd, currentX, currentY - 1, 3);
                }
                break;

            // down
            case (3):
                if ( ((currentY + 1 < 16) && (currentY + 2 < 16) && (maze[currentY + 3][currentX] == 0)) && ((maze[currentY + 1][currentX + 1] == 0) && (maze[currentY + 1][currentX - 1] == 0)) && ((maze[currentY + 2][currentX + 1] == 0) && (maze[currentY + 2][currentX - 1] == 0)))
                {
                    maze[currentY + 1][currentX] = 1;
                    maze[currentY + 2][currentX] = 1;
                    
                    generateMaze(maze, mazeTouch, mazeStartEnd, currentX, currentY + 1, 2);
                }
                break;
            }
        }
    }
}

// saying that the maze ends there
//}

void drawRobot(int x, int y, int direction)
{
    foreground();
    setColour(blue);
    sleep(10);
    clear();
    fillArc(x * 40 + 5, y * 40 + 5, 30, 30, 0, 360);
}

void solveMaze(int mazeStartEnd[4], int direction)
{
    int robotX = mazeStartEnd[0];
    int robotY = mazeStartEnd[1];

    // make empty list, then add items whenever a new step is made, then use it at end as the solved maze path

    switch (direction % 4)
    {

    // Right
    case (0):
        break;

    // Down
    case (1):
        break;

    // Left
    case (2):
        break;

    // Up
    case (3):
        break;
    }
}

void endFound()
{
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
// int maze[17][17] = { {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} , {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1} };

// Robot should only be able to see in 4 directions, hence see maze[i][i], maze[i+1][i], maze[i-1][i], maze[i][i+1], maze[i][i-1]

int main()
{

    srand((unsigned int)time(NULL));

    setWindowSize(CanvasWidth, CanvasHeight);

    // int maze[17][17] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    //  Array containing start and end of maze
    int mazeStartEnd[4];

    // change to calloc, so memory gets allocated and bits get changed to 0. This prevents old memory from being accessed.
    // int maze[17][17] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int maze[17][17];
    int mazeTouch[17][17];

    resetMaze(maze);
    resetMaze(mazeTouch);

    int currentX = 1;
    int currentY = 1;

    maze[1][0] = 1;
    maze[currentY][currentX] = 1;

    generateMaze(maze, mazeTouch, mazeStartEnd, currentX, currentY, 0);

    // Creating a valid exit on the rightmost side.
    createExit(maze);

    drawMaze(maze);

    // solveMaze(mazeStartEnd, 0);

    // Condition should be so that it moves in a new direction continously.

    // Take rights until at dead ends, then take lefts

    // end sequence as loop ends when maze end is found but not travelled to.

    // endFound();

    return 0;
}