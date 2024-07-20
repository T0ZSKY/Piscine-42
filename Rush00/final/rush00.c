/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:08:02 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/20 12:52:19 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern void	ft_putchar(char c);

void	ft_if(int x, int y, int i, int j)
{
	char	co;
	char	vide;
	char	lign;
	char	col;

	co = 'o';
	vide = ' ';
	col = '|';
	lign = '-';
	if ((i == 0 && j == 0)
		|| (i == 0 && j == x -1)
		|| (i == y - 1 && j == 0)
		|| (i == y - 1 && j == x -1))
		ft_putchar(co);
	else if (i == 0 || i == y - 1)
		ft_putchar(lign);
	else if (j == 0 || j == x - 1)
		ft_putchar(col);
	else
		ft_putchar(vide);
}

void	ft_loop(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_if(x, y, i, j);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
		write(1, "ecrit un nombre positif", 23);
	ft_loop(x, y);
}
