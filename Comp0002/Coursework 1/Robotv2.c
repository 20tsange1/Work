// Use a 2D array for the maze.
// Make the robot consider both sides and record down how many steps.

#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include <time.h>



#define Gridheight 17
#define Gridwidth 17

#define SideLength 40

#define CanvasHeight (SideLength * Gridheight)
#define CanvasWidth (SideLength * Gridwidth)

#define BotDiameter SideLength*3/4

#define BotOffset (SideLength - BotDiameter)/2

#define Right 0
#define Down 1
#define Left 2
#define Up 3



void drawMaze(int maze[Gridheight][Gridwidth])
{
    background();
    setColour(black);

    for (int y = 0; y < Gridheight; y++)
    {
        for (int x = 0; x < Gridwidth; x++)
        {
            if (maze[y][x] == 1)
            {
                setColour(white);
            }
            else
            {
                setColour(black);
            }
            fillRect(x * SideLength, y * SideLength, x * SideLength + SideLength, y * SideLength + SideLength);
            setColour(black);
            drawRect(x * SideLength, y * SideLength, x * SideLength + SideLength, y * SideLength + SideLength);
        }
    }
}

void resetMaze(int maze[Gridheight][Gridwidth])
{

    for (int y = 0; y < Gridheight; y++)
    {
        for (int x = 0; x < Gridwidth; x++)
        {
            maze[y][x] = 0;
        }
    }
}

int createExit(int maze[Gridheight][Gridwidth])
{
    for (int i = Gridheight - 1; i > 1; i--)
    {
        if (maze[i][Gridwidth - 2] == 1) // To check if there is a valid previous passage to enter from.
        {
            maze[i][Gridwidth - 1] = 1;
            return i;
        }
    }
    return -1;
}

int mazeTouched(int mazeTouch[Gridheight][Gridwidth])
{
    for (int y = 0; y < Gridheight; y++)
    {
        for (int x = 0; x < Gridwidth; x++)
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
void generateMaze(int maze[Gridheight][Gridwidth], int currentX, int currentY, int prevOrientation)
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
            switch (direction)
            {

            // left
            case (0):
                // Checks if the area on the side is still within the bounds and if there is enough space to create a new path, then it checks if a valid path can be created which requires both sides to be walls.
                if (((currentX - 1 > 0) && (maze[currentY][currentX - 2] == 0)) && ((maze[currentY + 1][currentX - 1] == 0) && (maze[currentY - 1][currentX - 1] == 0)))
                {
                    maze[currentY][currentX - 1] = 1;
                    generateMaze(maze, currentX - 1, currentY, 1);
                }
                break;

            // right
            case (1):
                if (((currentX + 1 < Gridwidth - 1) && (maze[currentY][currentX + 2] == 0)) && ((maze[currentY + 1][currentX + 1] == 0) && (maze[currentY - 1][currentX + 1] == 0)))
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
                if (((currentY + 1 < Gridheight - 1) && (maze[currentY + 2][currentX] == 0)) && ((maze[currentY + 1][currentX + 1] == 0) && (maze[currentY + 1][currentX - 1] == 0)))
                {
                    maze[currentY + 1][currentX] = 1;
                    generateMaze(maze, currentX, currentY + 1, 2);
                }
                break;
            }
        }
    }
}

void generateLoopMaze(int maze[Gridheight][Gridwidth], int currentX, int currentY, int prevOrientation)
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
                if ((currentX + 1 < Gridwidth - 1) && ((maze[currentY + 1][currentX + 1] == 0) && (maze[currentY - 1][currentX + 1] == 0)))
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
                if ((currentY + 1 < Gridheight - 1) && ((maze[currentY + 1][currentX + 1] == 0) && (maze[currentY + 1][currentX - 1] == 0)))
                {
                    maze[currentY + 1][currentX] = 1;
                    generateLoopMaze(maze, currentX, currentY + 1, 2);
                }
                break;
            }
        }
    }
}


void drawRobot(int x, int y, int direction)
{
    foreground();
    setColour(blue);

    // Creates illusion of movement by redrawing the robot 40 times.
    for (int i = 0; i < SideLength; i++)
    {
        sleep(5);
        clear();

        switch (direction)
        {
        case (Right):
            fillArc((x - 1) * SideLength + BotOffset + i, y * SideLength + BotOffset, BotDiameter, BotDiameter, 0, 360);
            break;

        case (Down):
            fillArc(x * SideLength + BotOffset, (y - 1) * SideLength + BotOffset + i, BotDiameter, BotDiameter, 0, 360);
            break;

        case (Left):
            fillArc((x + 1) * SideLength + BotOffset - i, y * SideLength + BotOffset, BotDiameter, BotDiameter, 0, 360);
            break;

        case (Up):
            fillArc(x * SideLength + BotOffset, (y + 1) * SideLength + BotOffset - i, BotDiameter, BotDiameter, 0, 360);
            break;
        }
    }
}

// As robot shouldn't directly have access to map layout.
int canMoveForward(int maze[Gridheight][Gridwidth], int robotX, int robotY, int direction)
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

int atMarker(int mazeEnd[2], int robotX, int robotY)
{
    if ((robotX == mazeEnd[0]) && (robotY == mazeEnd[1]))
    {
        return 1;
    }
    else
    {
        return 0;
    }

    return -1;
}

void forward(int* direction, int* robotX, int* robotY)
{
    switch (*direction)
    {
    // Right
    case (Right):
        *robotX += 1;
        break;

    // DownX
    case (Down):
        *robotY += 1;
        break;

    // Left
    case (Left):
        *robotX -= 1;
        break;

    // Up
    case (Up):
        *robotY -= 1;
        break;
    }

}

void left(int* direction)
{
    switch (*direction)
    {
    // Right
    case (Right):
        *direction = Up;
        break;

    // DownX
    case (Down):
        *direction = Right;
        break;

    // Left
    case (Left):
        *direction = Down;
        break;

    // Up
    case (Up):
        *direction = Left;
        break;
    }
}

void right(int* direction)
{
    switch (*direction)
    {
    // Right
    case (Right):
        *direction = Down;
        break;

    // DownX
    case (Down):
        *direction = Left;
        break;

    // Left
    case (Left):
        *direction = Up;
        break;

    // Up
    case (Up):
        *direction = Right;
        break;
    }
}

void solveMaze(int maze[Gridheight][Gridwidth], int mazeEnd[2], int mazeStart[2], int* direction, int* robotX, int* robotY)
{

    // make empty list, then add items whenever a new step is made, then use it at end as the solved maze path

    // go forward, left, right, back, anything but the same direction you came in.

    int success = 1;

    // Algorithm keeps the wall on the right

    while (!atMarker(mazeEnd, *robotX, *robotY))
    {

        // Success variable is so it only animates a move if there is an actual movement, not when there is a turn.
        if (success == 1)
        {
            drawRobot(*robotX, *robotY, *direction);
        }

        success = 0;

        switch (*direction)
        {
        // Right
        case (Right):
            // Facing right
            if ((canMoveForward(maze, *robotX, *robotY, Down) == 0) && (canMoveForward(maze, *robotX, *robotY, Right) == 1))
            {
                forward(&*direction, &*robotX, &*robotY); // not actually needed, but here for requirements
                success = 1;
            }
            else if (canMoveForward(maze, *robotX, *robotY, Down) == 1)
            {
                right(&*direction);
                forward(&*direction, &*robotX, &*robotY);
                success = 1;
            }
            else if (canMoveForward(maze, *robotX, *robotY, Right) == 0)
            {
                left(&*direction);
            }

            break;

        // Down
        case (Down):
            // Facing down
            if ((canMoveForward(maze, *robotX, *robotY, Left) == 0) && (canMoveForward(maze, *robotX, *robotY, Down) == 1))
            {
                forward(&*direction, &*robotX, &*robotY);
                success = 1;
            }
            else if (canMoveForward(maze, *robotX, *robotY, Left) == 1)
            {
                right(&*direction);
                forward(&*direction, &*robotX, &*robotY);
                success = 1;
            }
            else if (canMoveForward(maze, *robotX, *robotY, Down) == 0)
            {
                left(&*direction);
            }

            break;

        // Left
        case (Left):
            // Facing left
            if ((canMoveForward(maze, *robotX, *robotY, Up) == 0) && (canMoveForward(maze, *robotX, *robotY, Left) == 1))
            {
                forward(&*direction, &*robotX, &*robotY);
                success = 1;
            }
            else if ((canMoveForward(maze, *robotX, *robotY, Up) == 1))
            {
                right(&*direction);
                forward(&*direction, &*robotX, &*robotY);
                success = 1;
            }
            else if (canMoveForward(maze, *robotX, *robotY, Left) == 0)
            {
                left(&*direction);
            }

            break;

        // Up
        case (Up):
            // Facing up
            if ((canMoveForward(maze, *robotX, *robotY, Right) == 0) && (canMoveForward(maze, *robotX, *robotY, Up) == 1))
            {
                forward(&*direction, &*robotX, &*robotY);
                success = 1;
            }
            else if ((canMoveForward(maze, *robotX, *robotY, Right) == 1))
            {
                right(&*direction);
                forward(&*direction, &*robotX, &*robotY);
                success = 1;
            }
            else if (canMoveForward(maze, *robotX, *robotY, Up) == 0)
            {
                left(&*direction);
            }

            break;
        }
    }

    drawRobot(*robotX, *robotY, *direction);
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
    drawString("Robot has solved the maze", 280, 340);
}

// Example basic maze ( 0 = black 1 = white)

int main()
{
    // Initialisation of a new seed for the random function.
    srand((unsigned int)time(NULL));

    setWindowSize(CanvasWidth, CanvasHeight);

    int maze[Gridheight][Gridwidth];
    int mazeTouch[Gridheight][Gridwidth];

    int currentX = 1;
    int currentY = 1;
    int loop = 0;

    int mazeStart[2];
    int mazeEnd[2];

    int robotX;
    int robotY;

    int direction = 0;

    resetMaze(maze);
    resetMaze(mazeTouch);

    // As we have set the maze start at 0,1 (This can be changed if wanted with a similar function to creating the exit)
    mazeStart[0] = 0;
    mazeStart[1] = 1;

    robotX = mazeStart[0];
    robotY = mazeStart[1];

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
    mazeEnd[0] = Gridwidth - 1;
    mazeEnd[1] = createExit(maze);

    drawMaze(maze);

    // use pointers instead of returning
    solveMaze(maze, mazeEnd, mazeStart, &direction, &robotX, &robotY);

    endFound();

    return 0;
}