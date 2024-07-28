/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:07:01 by tomlimon          #+#    #+#             */
/*   Updated: 2024/07/28 10:13:13 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int check_col_up(char tab[6][6], int col) {
    int max;
    int visible;
    int row;

    max = '0';
    visible = 0;
    row = 1;
    while (row < 5) {
        if (tab[row][col] > max) {
            max = tab[row][col];
            visible++;
        }
        row++;
    }
    return (tab[0][col] == '0' || visible == tab[0][col] - '0');
}

int check_col_down(char tab[6][6], int col) {
    int max = '0';
    int visible = 0;
    int row = 4;

    while (row > 0) {
        if (tab[row][col] > max) {
            max = tab[row][col];
            visible++;
        }
        row--;
    }
    return (tab[5][col] == '0' || visible == tab[5][col] - '0');
}

int check_row_left(char tab[6][6], int row) {
    int max = '0';
    int visible = 0;
    int col = 1;

    while (col < 5) {
        if (tab[row][col] > max) {
            max = tab[row][col];
            visible++;
        }
        col++;
    }
    return (tab[row][0] == '0' || visible == tab[row][0] - '0');
}

int check_row_right(char tab[6][6], int row) {
    int max;
    int visible;
    int col;

    max = '0';
    visible = 0;
    col = 4;
    while (col > 0) {
        if (tab[row][col] > max) {
            max = tab[row][col];
            visible++;
        }
        col--;
    }
    return (tab[row][5] == '0' || visible == tab[row][5] - '0');
}

int check_visibility(char tab[6][6]) {
    int i;

    i = 1;
    while (i < 5) {
        if (!check_col_up(tab, i) || !check_col_down(tab, i) ||
            !check_row_left(tab, i) || !check_row_right(tab, i))
            return (0);
        i++;
    }
    return (1);
}