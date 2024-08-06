#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Ajouter cette ligne pour utiliser strlen

#define SIZE 20  // Changer la taille si nécessaire

// Définition des types booléens
typedef enum { false, true } bool;

// Affiche la grille
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

// Vérifie si on peut placer un carré
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

// Backtracking pour résoudre le problème du plus grand carré
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
                        break; // Stop checking larger tailles si la taille actuelle ne peut pas tenir
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
        if (fgets(grid[i], SIZE + 2, file) == NULL) {
            fclose(file);
            return false;
        }
        // Remplacer le saut de ligne par '\0' si la ligne est trop longue
        size_t len = strlen(grid[i]);
        if (len < SIZE) {
            grid[i][len] = '\0';  // Terminer la chaîne correctement
        } else {
            grid[i][SIZE - 1] = '\0';  // Assurez-vous que la chaîne est bien terminée
        }
        i++;
    }

    fclose(file);
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;  // Erreur d'utilisation, rien n'est affiché
    }

    char grid[SIZE][SIZE];
    
    if (!readGridFromFile(argv[1], grid)) {
        return 1;  // Erreur de lecture, rien n'est affiché
    }

    int bestSize = 0;
    int bestRow = 0;
    int bestCol = 0;

    if (solveBSQ(grid, &bestSize, &bestRow, &bestCol)) {
        placeSquare(grid, bestRow, bestCol, bestSize);
    }

    // Afficher uniquement la grille après le placement du carré
    printGrid(grid);

    return 0;
}