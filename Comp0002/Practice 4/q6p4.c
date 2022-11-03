#include <stdio.h>
#include <stdlib.h>

int** raggedarray(int rowsLength[7], int rows) {

    int** ragged = malloc(sizeof(*ragged) * rows);
    
    for (int i = 0; i < rows; i++) {
        ragged[i] = calloc(rowsLength[i], sizeof(*ragged[i]));
    }

    return ragged;

}

void printRA(int ** raggedarray, int rowsLength[7], int rows) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rowsLength[i]; j++) {
            printf("%i ", raggedarray[i][j]);
        }
        printf("\n");
    }

}

int main() {
    int rowsLength[7] = {2, 6, 3, 9, 9, 5, 3};
    int rows = sizeof(rowsLength)/sizeof(rowsLength[0]);

    int **ragged = raggedarray(rowsLength, rows);

    printRA(ragged, rowsLength, rows);


    free(ragged);
    return 0;
}