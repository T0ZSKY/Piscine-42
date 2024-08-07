#include <stdio.h>
#include <stdlib.h>

//def bool
typedef enum { false, true } bool;

#define SIZE 100  // taille de la map

//strlen
size_t my_strlen(const char *str) {
    size_t length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

// affichage map
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

// Vérifie pour place
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

// Place un carré
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

// Supprime un carré
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

// Backtracking pour résoudre
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
                        break; 
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

// Lire la carte depuis le fichier
bool readGridFromFile(const char *filename, char grid[SIZE][SIZE]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return false;
    }

    // Ignorer la première ligne
    char buffer[SIZE + 2];
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        fclose(file);
        return false;
    }

    int i = 0;
    while (i < SIZE) {
        if (fgets(buffer, sizeof(buffer), file) == NULL) {
            break; // Stop if no more lines are available
        }
        size_t len = my_strlen(buffer);
        if (len > SIZE) len = SIZE;
        int j = 0;
        while (j < len) {
            grid[i][j] = buffer[j];
            j++;
        }
        // Remplir le reste de la ligne avec des '.'
        while (j < SIZE) {
            grid[i][j] = '.';
            j++;
        }
        i++;
    }

    fclose(file);
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
        return 1;  // Erreur ouverture
    }

    char grid[SIZE][SIZE];
    
    if (!readGridFromFile(argv[1], grid)) {
        return 1;  // Erreur de lecture
    }

    int bestSize = 0;
    int bestRow = 0;
    int bestCol = 0;

    if (solveBSQ(grid, &bestSize, &bestRow, &bestCol)) {
        placeSquare(grid, bestRow, bestCol, bestSize);
    }

    printGrid(grid);

    return 0;
}