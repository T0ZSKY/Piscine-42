/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:35:38 by tomlimon          #+#    #+#             */
/*   Updated: 2024/07/28 13:18:47 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "rush01.h"

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
        if (!(str[i] >= '1' && str[i] <= '4') && !(str[i] == ' ')) {
            return (1);
        }
        i++;
    }
    return (0);
}

void print_solution(char tab[6][6]) {
    int i = 1;
    while (i < 5) {
        int j = 1;
        while (j < 5) {
            write(1, &tab[i][j], 1);
            if (j < 4) {
                write(1, " ", 1);
            }
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

int is_valid(char tab[6][6], int row, int col, char num) {
    int i = 1;
    while (i <= 4) {
        if (tab[row][i] == num || tab[i][col] == num) {
            return (0);
        }
        i++;
    }
    return (1);
}

int solve_puzzle(char tab[6][6], int pos) {
    int row = pos / 4 + 1;
    int col = pos % 4 + 1;
    char num = '1';

    if (pos == 16) {
        return check_visibility(tab);
    }
    if (tab[row][col] != '0') {
        return solve_puzzle(tab, pos + 1);
    }
    while (num <= '4') {
        if (is_valid(tab, row, col, num)) {
            tab[row][col] = num;
            if (solve_puzzle(tab, pos + 1)) {
                return (1);
            }
            tab[row][col] = '0';
        }
        num++;
    }
    return (0);
}
