/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 09:12:35 by tomlimon          #+#    #+#             */
/*   Updated: 2024/07/28 09:54:25 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// main.c
#include <unistd.h>

#include "rush01.h"

int main(int argc, char *argv[])
{
    char tab[6][6] = {
        {' ', argv[1][0], argv[1][2], argv[1][4], argv[1][6], ' '},
        {argv[1][16], '0', '0', '0', '0', argv[1][24]},
        {argv[1][18], '0', '0', '0', '0', argv[1][26]},
        {argv[1][20], '0', '0', '0', '0', argv[1][28]},
        {argv[1][22], '0', '0', '0', '0', argv[1][30]},
        {' ', argv[1][8], argv[1][10], argv[1][12], argv[1][14], ' '}
    };

    if (argc != 2)
    {
        write(1, "Error\n", 6);
        return (1);
    }
    if (ft_strlen(argv[1]) != 31)
    {
        write(1, "Error\n", 6);
        return (ft_strlen(argv[1]));
    }
    if (ft_check(argv[1]) == 1)
    {
        write(1, "Error\n", 6);
        return (1);
    }
    if (!solve_puzzle(tab, 0))
    {
        write(1, "Error\n", 6);
        return (1);
    }
    print_solution(tab);
    return (0);
}