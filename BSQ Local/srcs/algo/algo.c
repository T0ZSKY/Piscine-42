#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

// Définitions des booléens
typedef enum { false, true } bool;

// Lecture de la taille de la grille depuis le fichier
int readGridSize(int fd) {
    char buffer[10];
    int bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead <= 0) {
        write(2, "Error reading grid size\n", 25);
        exit(EXIT_FAILURE);
    }
    buffer[bytesRead] = '\0'; // Terminer la chaîne
    return atoi(buffer);
}

// Lecture de la grille depuis le fichier
bool readGridFromFile(const char *filename, char ***grid, int *size) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        write(2, "Error opening file\n", 20);
        return false;
    }

    *size = readGridSize(fd);
    *grid = (char **)malloc((*size) * sizeof(char *));
    if (*grid == NULL) {
        write(2, "Memory allocation failed\n", 26);
        close(fd);
        return false;
    }

    for (int i = 0; i < *size; i++) {
        (*grid)[i] = (char *)malloc((*size) * sizeof(char));
        if ((*grid)[i] == NULL) {
            write(2, "Memory allocation failed\n", 26);
            close(fd);
            return false;
        }
    }

    char buffer[BUFFER_SIZE];
    int row = 0;
    int col = 0;
    ssize_t bytesRead;
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        for (ssize_t j = 0; j < bytesRead; j++) {
            if (buffer[j] == '\n') {
                row++;
                col = 0;
                if (row >= *size) break;
            } else {
                (*grid)[row][col++] = buffer[j];
            }
        }
        if (row >= *size) break; // Sortir si la grille est entièrement remplie
    }

    close(fd);
    return true;
}

// Affiche la grille
void printGrid(char **grid, int size) {
    for (int i = 0; i < size; i++) {
        write(1, grid[i], size);
        write(1, "\n", 1);
    }
}

// Vérifie si on peut placer un carré à une position donnée
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

// Place un carré dans la grille
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

// Résolution par backtracking pour trouver le plus grand carré
bool solveBSQ(char **grid, int size, int *bestSize, int *bestRow, int *bestCol, char emptyChar) {
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
        write(2, "Usage: <program> <map_file> [<map_file> ...]\n", 45);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        char **grid;
        int size;
        if (!readGridFromFile(argv[i], &grid, &size)) {
            write(2, "Error reading file\n", 20);
            continue;
        }

        int bestSize = 0;
        int bestRow = 0;
        int bestCol = 0;

        if (solveBSQ(grid, size, &bestSize, &bestRow, &bestCol, '.')) {
            char result[100];
            int len = snprintf(result, sizeof(result), "Best square size: %d at (%d, %d)\n", bestSize, bestRow, bestCol);
            write(1, result, len);
            placeSquare(grid, bestRow, bestCol, bestSize, 'x');
        } else {
            write(1, "No square found.\n", 18);
        }

        printGrid(grid, size);

        for (int j = 0; j < size; j++) {
            free(grid[j]);
        }
        free(grid);
    }

    return 0;
}