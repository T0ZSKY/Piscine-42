/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 09:12:35 by tomlimon          #+#    #+#             */
/*   Updated: 2024/07/28 13:18:36 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
    char tab[6][6];

    if (check_args(argc, argv) == 0)
    {
        write(1, "Error\n", 6);
        return (1);
    }
    
    init_tab(tab, argv[1]);

    if (!solve_puzzle(tab, 0))
    {
        write(1, "Error\n", 6);
        return (1);
    }

    print_solution(tab);
    return (0);
}