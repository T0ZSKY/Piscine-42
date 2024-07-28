/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledupon <aledupon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:35:07 by tomlimon          #+#    #+#             */
/*   Updated: 2024/07/28 10:46:07 by aledupon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	init_edges(char tab[6][6])
{
	tab[0][0] = ' ';
	tab[0][5] = ' ';
	tab[5][0] = ' ';
	tab[5][5] = ' ';
}

void	init_rows_and_cols(char tab[6][6], char *arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 4)
	{
		tab[0][j + 1] = arg[i];
		tab[5][j + 1] = arg[i + 8];
		tab[j + 1][0] = arg[i + 16];
		tab[j + 1][5] = arg[i + 24];
		i += 2;
		j++;
	}
}

void	init_interior(char tab[6][6])
{
	int	i;
	int	j;

	i = 1;
	while (i <= 4)
	{
		j = 1;
		while (j <= 4)
		{
			tab[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	init_tab(char tab[6][6], char *arg)
{
	init_edges(tab);
	init_rows_and_cols(tab, arg);
	init_interior(tab);
}
