// Use a 2D array for the maze.
// Make the robot consider both sides and record down how many steps.

#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include <time.h>

#define CanvasWidth 680
#define CanvasHeight 680

#define Right 0
#define Down 1
#define Left 2
#define Up 3

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

// Recursive algorithm to generate maze by exploring path possibilities.
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
                // Checks if the left hand box is still valid (within maze size) and then checks if opening that box will allow for a valid passage (two walls on the left and the right of it)
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

    // Creates illusion of movement by redrawing the robot 40 times.
    for (int i = 0; i < 40; i++)
    {
        sleep(10);
        clear();

        switch (direction)
        {
        case (Right):
            fillArc((x - 1) * 40 + 5 + i, y * 40 + 5, 30, 30, 0, 360);
            break;

        case (Down):
            fillArc(x * 40 + 5, (y - 1) * 40 + 5 + i, 30, 30, 0, 360);
            break;

        case (Left):
            fillArc((x + 1) * 40 + 5 - i, y * 40 + 5, 30, 30, 0, 360);
            break;

        case (Up):
            fillArc(x * 40 + 5, (y + 1) * 40 + 5 - i, 30, 30, 0, 360);
            break;
        }
    }
}

// As robot shouldn't directly have access to map layout.
int queryMaze(int maze[17][17], int robotX, int robotY, int direction)
{

    switch (direction)
    {
    case (Right):
        return (maze[robotY][robotX + 1]);
        break;

    case (Down):
        return (maze[robotY + 1][robotX]);
        break;

    case (Left):
        return (maze[robotY][robotX - 1]);
        break;

    case (Up):
        return (maze[robotY - 1][robotX]);
        break;
    }
    return 0;
}

void solveMaze(int maze[17][17], int mazeEnd[2], int mazeStart[2], int direction)
{

    // make empty list, then add items whenever a new step is made, then use it at end as the solved maze path

    // go forward, left, right, back, anything but the same direction you came in.

    int robotX = mazeStart[0];
    int robotY = mazeStart[1];
    int success = 1;

    // Wall on right

    while ((robotX != mazeEnd[0]) || (robotY != mazeEnd[1]))
    {

        // Success variable is so it only animates a move if there is an actual movement, not when there is a turn.
        if (success == 1)
        {
            drawRobot(robotX, robotY, direction);
        }

        success = 0;

        printf("X %i -- Y %i  Direction %i\n", robotX, robotY, direction);

        switch (direction)
        {
        // Right
        case (Right):
            // Facing right
            if ((queryMaze(maze, robotX, robotY, Down) == 0) && (queryMaze(maze, robotX, robotY, Right) == 1))
            {
                robotX += 1;
                success = 1;
            }
            else if (queryMaze(maze, robotX, robotY, Down) == 1)
            {
                direction = Down;
                robotY += 1;
                success = 1;
            }
            else if (queryMaze(maze, robotX, robotY, Right) == 0)
            {
                direction = Up;
            }

            break;

        // Down
        case (Down):
            // Facing down
            if ((queryMaze(maze, robotX, robotY, Left) == 0) && (queryMaze(maze, robotX, robotY, Down) == 1))
            {
                robotY += 1;
                success = 1;
            }
            else if (queryMaze(maze, robotX, robotY, Left) == 1)
            {
                direction = Left;
                robotX -= 1;
                success = 1;
            }
            else if (queryMaze(maze, robotX, robotY, Down) == 0)
            {
                direction = Right;
            }

            break;

        // Left
        case (Left):
            // Facing left
            if ((queryMaze(maze, robotX, robotY, Up) == 0) && (queryMaze(maze, robotX, robotY, Left) == 1))
            {
                robotX -= 1;
                success = 1;
            }
            else if ((queryMaze(maze, robotX, robotY, Up) == 1))
            {
                direction = Up;
                robotY -= 1;
                success = 1;
            }
            else if (queryMaze(maze, robotX, robotY, Left) == 0)
            {
                direction = Down;
            }

            break;

        // Up
        case (Up):
            // Facing up
            if ((queryMaze(maze, robotX, robotY, Right) == 0) && (queryMaze(maze, robotX, robotY, Up) == 1))
            {
                robotY -= 1;
                success = 1;
            }
            else if ((queryMaze(maze, robotX, robotY, Right) == 1))
            {
                direction = Right;
                robotX += 1;
                success = 1;
            }
            else if (queryMaze(maze, robotX, robotY, Up) == 0)
            {
                direction = Left;
            }

            break;
        }
    }

    drawRobot(robotX, robotY, direction);
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

int main()
{

    srand((unsigned int)time(NULL));

    setWindowSize(CanvasWidth, CanvasHeight);

    // change to calloc? so memory gets allocated and bits get changed to 0. This prevents old memory from being accessed.

    int maze[17][17];
    int mazeTouch[17][17];

    resetMaze(maze);
    resetMaze(mazeTouch);

    int currentX = 1;
    int currentY = 1;
    int loop = 0;

    int mazeStart[2];
    mazeStart[0] = 0;
    mazeStart[1] = 1;

    maze[mazeStart[1]][mazeStart[0]] = 1;
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
    int mazeEnd[2];
    mazeEnd[0] = 16;
    mazeEnd[1] = createExit(maze);

    drawMaze(maze);

    // use pointers instead of returning
    solveMaze(maze, mazeEnd, mazeStart, 0);

    endFound();

    return 0;
}