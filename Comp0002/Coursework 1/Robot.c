// Use a 2D array for the maze.
// Make the robot consider both sides and record down how many steps.

#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include <time.h>

#define CanvasWidth 480
#define CanvasHeight 480

void drawMaze(int maze[12][12])
{
    background();
    setColour(black);

    for (int y = 0; y < 12; y++)
    {
        for (int x = 0; x < 12; x++)
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

void resetMaze(int maze[12][12])
{

    for (int y = 0; y < 12; y++)
    {
        for (int x = 0; x < 12; x++)
        {
            maze[y][x] = 0;
        }
    }
}

void generateMaze(int maze[12][12], int mazeStartEnd[4])
{

    srand(time(NULL));

    // make maze using probablistic approach, skewed to generate longer lines
    for (int i = 0; i < 12; i++)
    {
        maze[0][i] = 0;
    }

    maze[1][0] = 1;

    for (int y = 1; y < 12; y++)
    {
        for (int x = 1; x < 11; x++)
        {
            // add so that it can be generated on the left too. (if all 4 sides empty, extend)
            // add so that it can extend in any direction from 1 to some n length (Needs to include going left and going up)
            if ((((maze[y][x - 1] == 1) && (maze[y + 1][x] == 0 && maze[y - 1][x] == 0)) || ((maze[y - 1][x] == 1) && (maze[y][x + 1] == 0 && maze[y][x - 1] == 0)) && (rand() % 10 <= 8)))
            {
                maze[y][x] = 1;

                for (int i = x; i < (rand() % 5); i++)
                {
                    if (maze[y - 1][i] == 0 && maze[y + 1][i] == 0)
                    {
                        if (x < 11)
                        {
                            maze[y][i] = 1;
                        }
                    }
                }
                for (int i = y; i < (rand() % 5); i++)
                {
                    if (maze[i][x - 1] == 0 && maze[i][x + 1] == 0)
                    {
                        if (x < 11)
                        {
                            maze[i][x] = 1;
                        }
                    }
                }

                // saying that the maze ends there

                if (y == 11)
                {
                    mazeStartEnd[2] = x;
                    mazeStartEnd[3] = y;
                    break;
                }
            }
        }
    }

    mazeStartEnd[0] = 0;
    mazeStartEnd[1] = 1;
}

void drawRobot(int x, int y, int direction)
{
    foreground();
    setColour(blue);
    for (int i = 0; i < 40; i++)
    {
        sleep(10);
        clear();
        fillArc(x * 40 + 5, y * 40 + 5, 30, 30, 0, 360);
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
// int maze[12][12] = { {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} , {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1} };

// Robot should only be able to see in 4 directions, hence see maze[i][i], maze[i+1][i], maze[i-1][i], maze[i][i+1], maze[i][i-1]

int main()
{

    setWindowSize(CanvasWidth, CanvasHeight);

    // int maze[12][12] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    //  Array containing start and end of maze
    int mazeStartEnd[4];

    mazeStartEnd[0] = 0;
    mazeStartEnd[1] = 1;

    // mazeStartEnd[2] = 11;
    // mazeStartEnd[3] = 10;

    // change to calloc, so memory gets allocated and bits get changed to 0. This prevents old memory from being accessed.
    // int maze[12][12] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int maze[12][12];
    
    resetMaze(maze);

    generateMaze(maze, mazeStartEnd);

    drawMaze(maze);

    int robotX = mazeStartEnd[0];
    int robotY = mazeStartEnd[1];

    int lastRobotX = mazeStartEnd[0];
    int lastRobotY = mazeStartEnd[1];

    int currentDirection = 1; // Up Down = 1 Left Right = -1

    int direction = 3; // Up = 0 Down = 1 Right = 2 Left = 3

    while ((robotX != mazeStartEnd[2]) || (robotY != mazeStartEnd[3]))
    {
        drawRobot(robotX, robotY, direction);

        // Condition should be so that it moves in a new direction continously.

        // Take rights until at dead ends, then take lefts

        switch (direction % 4)
        {
        case (0):

            if ((maze[robotY + 1][robotX] == 1) && (maze[robotY][robotX + 1] == 0))
            {
                lastRobotY = robotY;
                robotY += 1;
            }
            else if (maze[robotY][robotX + 1] == 1)
            {
                lastRobotX = robotX;
                robotX += 1;
                direction = 1;
            }
            else
            {
                direction++;
            }

            break;

        case (1):

            if ((maze[robotY][robotX + 1] == 1) && (maze[robotY - 1][robotX] == 0))
            {
                lastRobotX = robotX;
                robotX += 1;
            }
            else if (maze[robotY - 1][robotX] == 1)
            {
                lastRobotY = robotY;
                robotY -= 1;
                direction = 2;
            }
            else
            {
                direction++;
            }

            break;

        case (2):

            if ((maze[robotY - 1][robotX] == 1) && (maze[robotY][robotX - 1] == 0))
            {
                lastRobotY = robotY;
                robotY -= 1;
            }
            else if (maze[robotY][robotX - 1] == 1)
            {
                lastRobotX = robotX;
                robotX -= 1;
                direction = 3;
            }
            else
            {
                direction++;
            }

            break;

        case (3):

            if ((maze[robotY][robotX - 1] == 1) && (maze[robotY + 1][robotX] == 0))
            {
                lastRobotX = robotX;
                robotX -= 1;
            }
            else if (maze[robotY + 1][robotX] == 1)
            {
                lastRobotY = robotY;
                robotY += 1;
                direction = 0;
            }
            else
            {
                direction++;
            }

            break;
        }

        printf("%i, %i -- %i, %i -- %i\n", robotX, robotY, lastRobotX, lastRobotY, direction);
    }

    // end sequence as loop ends when maze end is found but not travelled to.
    drawRobot(robotX, robotY, direction);
    direction = -1;
    drawRobot(robotX, robotY, direction);

    endFound();

    return 0;
}