// Rush01.c
#include "rush01.h"
#include <unistd.h>

int ft_strlen(char *src)
{
    int o = 0;
    while (src[o])
    {
        o++;
    }
    return (o);
}

int ft_check(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (!(str[i] >= '1' && str[i] <= '4') && !(str[i] == 32))
        {
            return (1);
        }
        i++;
    }
    return (0);
}

void print_solution(char tab[6][6])
{
    int i = 1;
    while (i < 5)
    {
        int j = 1;
        while (j < 5)
        {
            write(1, &tab[i][j], 1);
            if (j < 4)
            {
                write(1, " ", 1);
            }
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

int is_valid(char tab[6][6], int row, int col, char num)
{
    int i = 1;
    while (i < 5)
    {
        if (tab[row][i] == num || tab[i][col] == num)
        {
            return (0);
        }
        i++;
    }
    return (1);
}

int check_visibility(char tab[6][6])
{
    int i;
    int max;
    int visible;
    int j;

    i = 1;
    while (i < 5)
    {
        max = '0';
        visible = 0;
        j = 1;
        while (j < 5)
        {
            if (tab[j][i] > max)
            {
                max = tab[j][i];
                visible++;
            }
            j++;
        }
        if (tab[0][i] != '0' && visible != tab[0][i] - '0')
        {
            return (0);
        }
        i++;
    }
    i = 1;
    while (i < 5)
    {
        max = '0';
        visible = 0;
        j = 4;
        while (j > 0)
        {
            if (tab[j][i] > max)
            {
                max = tab[j][i];
                visible++;
            }
            j--;
        }
        if (tab[5][i] != '0' && visible != tab[5][i] - '0')
        {
            return (0);
        }
        i++;
    }
    i = 1;
    while (i < 5)
    {
        max = '0';
        visible = 0;
        j = 1;
        while (j < 5)
        {
            if (tab[i][j] > max)
            {
                max = tab[i][j];
                visible++;
            }
            j++;
        }
        if (tab[i][0] != '0' && visible != tab[i][0] - '0')
        {
            return (0);
        }
        i++;
    }
    i = 1;
    while (i < 5)
    {
        max = '0';
        visible = 0;
        j = 4;
        while (j > 0)
        {
            if (tab[i][j] > max)
            {
                max = tab[i][j];
                visible++;
            }
            j--;
        }
        if (tab[i][5] != '0' && visible != tab[i][5] - '0')
        {
            return (0);
        }
        i++;
    }
    return (1);
}

int solve_puzzle(char tab[6][6], int pos)
{
    int row = pos / 4 + 1;
    int col = pos % 4 + 1;
    char num;

    if (pos == 16)
    {
        return (check_visibility(tab));
    }
    if (tab[row][col] != '0')
    {
        return (solve_puzzle(tab, pos + 1));
    }
    num = '1';
    while (num <= '4')
    {
        if (is_valid(tab, row, col, num))
        {
            tab[row][col] = num;
            if (solve_puzzle(tab, pos + 1))
            {
                return (1);
            }
            tab[row][col] = '0';
        }
        num++;
    }
    return (0);
}