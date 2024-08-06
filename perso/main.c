#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


#define BUFFER_SIZE 1024 // Taille du buffer pour la lecture du fichier

// Prototypes des fonctions
int read_first_line(int fd, char *buffer, int *rows, char *empty_char, char *obstacle_char);
void skip_first_line(int fd, int offset);
void read_and_display_map(int fd);

int main(int argc, char **argv) {
    if (argc < 2) {
        char *usage_msg = "Usage: ./bsq <map_file>\n";
        write(2, usage_msg, 24);
        return 1;
    }

    // Ouvrir le fichier en lecture seule
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        char *error_open_msg = "Erreur lors de l'ouverture du fichier\n";
        write(2, error_open_msg, 34);
        return 1;
    }

    char line[BUFFER_SIZE];
    int rows = 0;
    char empty_char = '\0';
    char obstacle_char = '\0';

    // Lire la première ligne du fichier
    int bytes_read = read_first_line(fd, line, &rows, &empty_char, &obstacle_char);
    if (bytes_read < 0) {
        close(fd);
        write(2, "Erreur de lecture du fichier\n", 29);
        return 1;
    }

    // Passer à la ligne suivante après la première ligne
    skip_first_line(fd, bytes_read);

    // Lire et afficher le reste de la carte
    read_and_display_map(fd);

    // Fermer le fichier
    close(fd);
    return 0;
}

// Lire la première ligne pour extraire les dimensions de la carte et les caractères spéciaux
int read_first_line(int fd, char *buffer, int *rows, char *empty_char, char *obstacle_char) {
    // Lire jusqu'à BUFFER_SIZE - 1 octets du fichier
    int bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
    if (bytes_read <= 0) {
        return -1; // Erreur ou fichier vide
    }
    buffer[bytes_read] = '\0'; // Assurer la terminaison nulle du buffer

    int i = 0;
    while (i < bytes_read && buffer[i] != '\n') {
        if (buffer[i] >= '0' && buffer[i] <= '9') {
            // Calculer le nombre de lignes à partir des chiffres
            *rows = *rows * 10 + (buffer[i] - '0');
        } else if (buffer[i] == ' ') {
            i++;
            if (i < bytes_read) {
                // Lire le caractère représentant les espaces vides
                *empty_char = buffer[i];
                i++;
                if (i < bytes_read) {
                    // Lire le caractère représentant les obstacles
                    *obstacle_char = buffer[i];
                }
            }
            break;
        }
        i++;
    }

    // Assurer qu'il y a un caractère de nouvelle ligne après la première ligne
    if (i < bytes_read && buffer[i] == '\n') {
        return i + 1; // Retourner la longueur lue, y compris la nouvelle ligne
    }
    
    return bytes_read; // Retourner la longueur totale si pas de nouvelle ligne
}

// Passer à la ligne suivante après avoir lu la première ligne
void skip_first_line(int fd, int offset) {
    if (lseek(fd, offset, SEEK_SET) == -1) {
        write(2, "Erreur lors du repositionnement du fichier\n", 43);
        exit(1);
    }
}

// Lire et afficher le reste de la carte
void read_and_display_map(int fd) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while (1) {
        // Lire jusqu'à BUFFER_SIZE octets du fichier
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0) {
            write(2, "Erreur de lecture du fichier\n", 29);
            exit(1);
        }
        if (bytes_read == 0) {
            break; // Fin du fichier
        }
        // Écrire le contenu lu sur la sortie standard
        if (write(1, buffer, bytes_read) != bytes_read) {
            write(2, "Erreur d'écriture sur la sortie standard\n", 41);
            exit(1);
        }
    }
}