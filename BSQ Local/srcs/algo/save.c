#include <stdio.h>

#define SIZE 10

// Définition des types booléens
typedef enum { false, true } bool;

// affiche la grille
void printGrid(char grid[SIZE][SIZE]) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            printf("%c ", grid[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

// verif si on peut placer
bool canPlace(char grid[SIZE][SIZE], int row, int col, int size) {
    if (row + size > SIZE || col + size > SIZE) {
        return false;
    }

    int i = row;
    while (i < row + size) {
        int j = col;
        while (j < col + size) {
            if (grid[i][j] != '.') {
                return false;
            }
            j++;
        }
        i++;
    }
    return true;
}

// placer un carré
void placeSquare(char grid[SIZE][SIZE], int row, int col, int size) {
    int i = row;
    while (i < row + size) {
        int j = col;
        while (j < col + size) {
            grid[i][j] = 'x';
            j++;
        }
        i++;
    }
}

// supprime un carré
void removeSquare(char grid[SIZE][SIZE], int row, int col, int size) {
    int i = row;
    while (i < row + size) {
        int j = col;
        while (j < col + size) {
            grid[i][j] = '.';
            j++;
        }
        i++;
    }
}

// backtracking
bool solveBSQ(char grid[SIZE][SIZE], int *bestSize, int *bestRow, int *bestCol) {
    bool found = false;
    int maxSize = 0;
    int row = 0;

    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            if (grid[row][col] == '.') {
                int size = 1;
                while (size <= SIZE) {
                    if (canPlace(grid, row, col, size)) {
                        if (size > maxSize) {
                            maxSize = size;
                            *bestSize = size;
                            *bestRow = row;
                            *bestCol = col;
                            found = true;
                        }
                    } else {
                        break; // Stop checking larger sizes if the current size cannot fit
                    }
                    size++;
                }
            }
            col++;
        }
        row++;
    }
    
    return found;
}

int main() {
    char grid[SIZE][SIZE] = {
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', 'o', '.', '.', '.', '.', '.', 'o', '.', '.'},
        {'.', '.', '.', '.', 'o', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'o', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', 'o', '.', '.', '.', '.', '.', 'o', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', 'o', '.', '.', 'o', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'o', '.', '.', 'o', '.', '.', '.'}
    };

    int bestSize = 0;
    int bestRow = 0;
    int bestCol = 0;

    if (solveBSQ(grid, &bestSize, &bestRow, &bestCol)) {
        printf("Solution found with square size %d at position (%d, %d):\n", bestSize, bestRow, bestCol);
        placeSquare(grid, bestRow, bestCol, bestSize);
        printGrid(grid);
        removeSquare(grid, bestRow, bestCol, bestSize);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}