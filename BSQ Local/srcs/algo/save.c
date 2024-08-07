#include <stdio.h>
#include <stdlib.h>

// def des bool
typedef enum { false, true } bool;

// taille de la map
int readGridSize(FILE *file) {
    int size;
    fscanf(file, "%d", &size);
    return size;
}

// lecture
bool readGridFromFile(const char *filename, char ***grid, int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return false;
    }

    *size = readGridSize(file);
    *grid = (char **)malloc((*size) * sizeof(char *));
    int i = 0;
    while (i < *size) {
        (*grid)[i] = (char *)malloc((*size) * sizeof(char));
        i++;
    }

    int row = 0;
    while (row < *size) {
        int col = 0;
        while (col < *size) {
            fscanf(file, " %c", &((*grid)[row][col]));
            col++;
        }
        row++;
    }

    fclose(file);
    return true;
}

// affiche map
void printGrid(char **grid, int size) {
    int i = 0;
    while (i < size) {
        int j = 0;
        while (j < size) {
            printf("%c", grid[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

// verif si on peux placer
bool canPlace(char **grid, int row, int col, int squareSize, int gridSize, char emptyChar) {
    if (row + squareSize > gridSize || col + squareSize > gridSize) {
        return false;
    }

    int r = row;
    while (r < row + squareSize) {
        int c = col;
        while (c < col + squareSize) {
            if (grid[r][c] != emptyChar) {
                return false;
            }
            c++;
        }
        r++;
    }
    return true;
}

void placeSquare(char **grid, int row, int col, int squareSize, char fillChar) {
    int r = row;
    while (r < row + squareSize) {
        int c = col;
        while (c < col + squareSize) {
            grid[r][c] = fillChar;
            c++;
        }
        r++;
    }
}

// backtracking resolution
bool solveBSQ(char **grid, int size, int *bestSize, int *bestRow, int *bestCol, char emptyChar, char fillChar) {
    bool found = false;
    int maxSize = 0;

    int row = 0;
    while (row < size) {
        int col = 0;
        while (col < size) {
            if (grid[row][col] == emptyChar) {
                int squareSize = 1;
                while (squareSize <= size) {
                    if (canPlace(grid, row, col, squareSize, size, emptyChar)) {
                        if (squareSize > maxSize) {
                            maxSize = squareSize;
                            *bestSize = squareSize;
                            *bestRow = row;
                            *bestCol = col;
                            found = true;
                        }
                    } else {
                        break;
                    }
                    squareSize++;
                }
            }
            col++;
        }
        row++;
    }

    return found;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <map_file> [<map_file> ...]\n", argv[0]);
        return 1;
    }

    int i = 1;
    while (i < argc) {
        char **grid;
        int size;
        if (!readGridFromFile(argv[i], &grid, &size)) {
            fprintf(stderr, "Error reading file %s\n", argv[i]);
            i++;
            continue;
        }

        int bestSize = 0;
        int bestRow = 0;
        int bestCol = 0;

        if (solveBSQ(grid, size, &bestSize, &bestRow, &bestCol, '.', 'x')) {
            printf("Best square size: %d at (%d, %d)\n", bestSize, bestRow, bestCol);
            placeSquare(grid, bestRow, bestCol, bestSize, 'x');
        } else {
            printf("No square found.\n");
        }

        printGrid(grid, size);

        int j = 0;
        while (j < size) {
            free(grid[j]);
            j++;
        }
        free(grid);

        i++;
    }

    return 0;
}