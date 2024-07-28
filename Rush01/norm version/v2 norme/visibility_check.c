/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledupon <aledupon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:35:30 by tomlimon          #+#    #+#             */
/*   Updated: 2024/07/28 11:12:25 by aledupon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_col_up(char tab[6][6], int col)
{
	int		i;
	char	max;
	int		visible;

	i = 1;
	max = '0';
	visible = 0;
	while (i < 5)
	{
		if (tab[i][col] > max)
		{
			max = tab[i][col];
			visible++;
		}
		i++;
	}
	if (tab[0][col] != '0' && visible != tab[0][col] - '0')
		return (0);
	return (1);
}

int	check_col_down(char tab[6][6], int col)
{
	int		i;
	char	max;
	int		visible;

	i = 4;
	max = '0';
	visible = 0;
	while (i > 0)
	{
		if (tab[i][col] > max)
		{
			max = tab[i][col];
			visible++;
		}
		i--;
	}
	if (tab[5][col] != '0' && visible != tab[5][col] - '0')
		return (0);
	return (1);
}

int	check_row_left(char tab[6][6], int row)
{
	int		i;
	char	max;
	int		visible;

	i = 1;
	max = '0';
	visible = 0;
	while (i < 5)
	{
		if (tab[row][i] > max)
		{
			max = tab[row][i];
			visible++;
		}
		i++;
	}
	if (tab[row][0] != '0' && visible != tab[row][0] - '0')
		return (0);
	return (1);
}

int	check_row_right(char tab[6][6], int row)
{
	int		i;
	char	max;
	int		visible;

	i = 4;
	max = '0';
	visible = 0;
	while (i > 0)
	{
		if (tab[row][i] > max)
		{
			max = tab[row][i];
			visible++;
		}
		i--;
	}
	if (tab[row][5] != '0' && visible != tab[row][5] - '0')
		return (0);
	return (1);
}

int	check_visibility(char tab[6][6])
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (!check_col_up(tab, i) || !check_col_down(tab, i)
			|| !check_row_left(tab, i) || !check_row_right(tab, i))
			return (0);
		i++;
	}
	return (1);
}
