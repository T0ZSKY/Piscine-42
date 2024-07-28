// rush01.h
#ifndef RUSH01_H
# define RUSH01_H

int  ft_strlen(char *src);
int  ft_check(char *str);
void print_solution(char tab[6][6]);
int  is_valid(char tab[6][6], int row, int col, char num);
int  check_visibility(char tab[6][6]);
int  solve_puzzle(char tab[6][6], int pos);

#endif