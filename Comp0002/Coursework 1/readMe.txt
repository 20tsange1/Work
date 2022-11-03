The maze generation program utilises a 2D array and a recursive random direction maze path generator to build a maze. 
This is similar to DFS but is my own implementation.

The robot then attempts to solve the maze using the right hand to the wall rule.

When complete, the program will then print out the solution (shortest) path for the maze in red.

Pointers are used within the main functions where possible to alter variables declared in main without intialising new variables.

The maze can be generated with loops and without loops *.

Changing the maze sizings will need to be done within the source code itself at the top where the constant values are defined.

Values that can be changed:
- GridHeight
- GridWidth
- SideLength

Requirements:
    GridHeight * SideLength <= 680
    GridWidth * SideLength <= 1460

Program should be run using the following two commands:

gcc -o Robotv2 Robotv2.c graphics.c    
./Robotv2 LOOP | java -jar drawapp-2.0.jar

* Where LOOP must be replaced by either:
    0 = No loops
    1 = Loops

References:
https://www.tutorialspoint.com/c_standard_library/c_function_srand.htm (For use of srand)

