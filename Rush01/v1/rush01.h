/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:09:57 by tomlimon          #+#    #+#             */
/*   Updated: 2024/07/28 10:10:00 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>

int  ft_strlen(char *src);
int  ft_check(char *str);
void print_solution(char tab[6][6]);
int  is_valid(char tab[6][6], int row, int col, char num);
int  check_visibility(char tab[6][6]);
int  check_col_up(char tab[6][6], int col);
int  check_col_down(char tab[6][6], int col);
int  check_row_left(char tab[6][6], int row);
int  check_row_right(char tab[6][6], int row);
int  solve_puzzle(char tab[6][6], int pos);

#endif