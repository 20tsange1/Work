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

int createExit(int maze[17][17])
{
    for (int i = 16; i > 1; i--)
    {
        if (maze[i][15] == 1)
        {
            maze[i][16] = 1;
            return i;
        }
    }
    return -1;
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

void generateMaze(int maze[17][17], int currentX, int currentY, int prevOrientation)
{
    int direction;

    // This is so it starts at a random direction first before cycling through the rest.
    int dire = rand() % 4;

    for (int i = 0; i < 3; i++)
    {
        // So all 4 sides are attempted
        direction = (dire + i) % 4;

        // So it doesn't backtrack
        if (direction != prevOrientation)
        {

            printf("%i\n", direction);
            switch (direction)
            {

            // left
            case (0):
                if (((currentX - 1 > 0) && (maze[currentY][currentX - 2] == 0)) && ((maze[currentY + 1][currentX - 1] == 0) && (maze[currentY - 1][currentX - 1] == 0)))
                {
                    maze[currentY][currentX - 1] = 1;
                    generateMaze(maze, currentX - 1, currentY, 1);
                }
                break;

            // right
            case (1):
                if (((currentX + 1 < 16) && (maze[currentY][currentX + 2] == 0)) && ((maze[currentY + 1][currentX + 1] == 0) && (maze[currentY - 1][currentX + 1] == 0)))
                {
                    maze[currentY][currentX + 1] = 1;
                    generateMaze(maze, currentX + 1, currentY, 0);
                }
                break;

            // up
            case (2):
                if (((currentY - 1 > 0) && (maze[currentY - 2][currentX] == 0)) && ((maze[currentY - 1][currentX + 1] == 0) && (maze[currentY - 1][currentX - 1] == 0)))
                {
                    maze[currentY - 1][currentX] = 1;
                    generateMaze(maze, currentX, currentY - 1, 3);
                }
                break;

            // down
            case (3):
                if (((currentY + 1 < 16) && (maze[currentY + 2][currentX] == 0)) && ((maze[currentY + 1][currentX + 1] == 0) && (maze[currentY + 1][currentX - 1] == 0)))
                {
                    maze[currentY + 1][currentX] = 1;
                    generateMaze(maze, currentX, currentY + 1, 2);
                }
                break;
            }
        }
    }
}

void generateLoopMaze(int maze[17][17], int currentX, int currentY, int prevOrientation)
{
    int direction;

    // This is so it starts at a random direction first before cycling through the rest.
    int dire = rand() % 4;

    for (int i = 0; i < 3; i++)
    {
        // Tries all sides
        direction = (dire + i) % 4;

        // So it doesn't backtrack while generating
        if (direction != prevOrientation)
        {

            printf("%i\n", direction);
            switch (direction)
            {

            // left
            case (0):
                if ((currentX - 1 > 0) && ((maze[currentY + 1][currentX - 1] == 0) && (maze[currentY - 1][currentX - 1] == 0)))
                {
                    maze[currentY][currentX - 1] = 1;
                    generateLoopMaze(maze, currentX - 1, currentY, 1);
                }
                break;

            // right
            case (1):
                if ((currentX + 1 < 16) && ((maze[currentY + 1][currentX + 1] == 0) && (maze[currentY - 1][currentX + 1] == 0)))
                {
                    maze[currentY][currentX + 1] = 1;
                    generateLoopMaze(maze, currentX + 1, currentY, 0);
                }
                break;

            // up
            case (2):
                if ((currentY - 1 > 0) && ((maze[currentY - 1][currentX + 1] == 0) && (maze[currentY - 1][currentX - 1] == 0)))
                {
                    maze[currentY - 1][currentX] = 1;
                    generateLoopMaze(maze, currentX, currentY - 1, 3);
                }
                break;

            // down
            case (3):
                if ((currentY + 1 < 16) && ((maze[currentY + 1][currentX + 1] == 0) && (maze[currentY + 1][currentX - 1] == 0)))
                {
                    maze[currentY + 1][currentX] = 1;
                    generateLoopMaze(maze, currentX, currentY + 1, 2);
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

    // change to calloc? so memory gets allocated and bits get changed to 0. This prevents old memory from being accessed.
    // int maze[17][17] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int maze[17][17];
    int mazeTouch[17][17];

    resetMaze(maze);
    resetMaze(mazeTouch);

    int currentX = 1;
    int currentY = 1;
    int loop = 0;

    maze[1][0] = 1;
    maze[currentY][currentX] = 1;

    switch (loop)
    {
    case (0):
        generateMaze(maze, currentX, currentY, 0);
        break;

    case (1):
        generateLoopMaze(maze, currentX, currentY, 0);
        break;
    }

    // Creating a valid exit on the rightmost side.
    int mazeEnd = createExit(maze);

    drawMaze(maze);

    // solveMaze(0);

    // Condition should be so that it moves in a new direction continously.

    // Take rights until at dead ends, then take lefts

    // end sequence as loop ends when maze end is found but not travelled to.

    return 0;
}