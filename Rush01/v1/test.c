#include <unistd.h>

int ft_strlen(char *src) {
    int o = 0;
    while (src[o]) {
        o++;
    }
    return (o);
}

int ft_check(char *str) {
    int i = 0;
    while (str[i]) {
        if (!(str[i] >= '1' && str[i] <= '4')) {
            return (1);
        }
        i++;
    }
    return (0);
}

void print_tab(char tab[6][6]) {
    int i = 0;
    while (i < 6) {
        int j = 0;
        while (j < 6) {
            write(1, &tab[i][j], 1);
            write(1, " ", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

void fill_center(char tab[6][6]) {
    for (int i = 1; i < 5; i++) {
        // Remplissage des colonnes en fonction des contraintes haut/bas
        if (tab[0][i] == '4') {
            tab[1][i] = '1';
            tab[2][i] = '2';
            tab[3][i] = '3';
            tab[4][i] = '4';
        } else if (tab[5][i] == '4') {
            tab[1][i] = '4';
            tab[2][i] = '3';
            tab[3][i] = '2';
            tab[4][i] = '1';
        } else if (tab[0][i] == '1') {
            tab[1][i] = '4';
        } else if (tab[5][i] == '1') {
            tab[4][i] = '4';
        }

        // Remplissage des lignes en fonction des contraintes gauche/droite
        if (tab[i][0] == '4') {
            tab[i][1] = '1';
            tab[i][2] = '2';
            tab[i][3] = '3';
            tab[i][4] = '4';
        } else if (tab[i][5] == '4') {
            tab[i][1] = '4';
            tab[i][2] = '3';
            tab[i][3] = '2';
            tab[i][4] = '1';
        } else if (tab[i][0] == '1') {
            tab[i][1] = '4';
        } else if (tab[i][5] == '1') {
            tab[i][4] = '4';
        }
    }
}

int main(int argc, char *argv[]) {
    // Gestion des erreurs
    if (argc != 2) {
        write(1, "Error\n", 6);
        return 1;
    }

    if (ft_strlen(argv[1]) != 16) {
        write(1, "Error\n", 6);
        return 1;
    }

    if (ft_check(argv[1]) == 1) {
        write(1, "Error\n", 6);
        return 1;
    }

    // Initialisation du tableau avec les contraintes
    char tab[6][6] = {
        {' ', argv[1][0], argv[1][1], argv[1][2], argv[1][3], ' '},
        {argv[1][4], '0', '0', '0', '0', argv[1][5]},
        {argv[1][6], '0', '0', '0', '0', argv[1][7]},
        {argv[1][8], '0', '0', '0', '0', argv[1][9]},
        {argv[1][10], '0', '0', '0', '0', argv[1][11]},
        {' ', argv[1][12], argv[1][13], argv[1][14], argv[1][15], ' '}
    };

    // Remplissage des centres du tableau
    fill_center(tab);

    // Imprimer le tableau
    print_tab(tab);

    return 0;
}
