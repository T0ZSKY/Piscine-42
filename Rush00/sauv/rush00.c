/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:56:42 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/20 11:38:13 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern void ft_putchar(char c);

void	ft_corners(int	i, int	j, int	x, int	y, char H, char co, char vi, char L)
{
	if ((i == 0 && j == 0)
		|| (i == 0 && j == x - 1)
		|| (i == y - 1 && j == 0)
		|| (i == y - 1 && j == x - 1))
	{
		ft_putchar(co);
	}
	else if (i == 0 || i == y - 1)
	{
		ft_putchar(L);
	}
	else if (j == 0 || j == x - 1)
	{
		ft_putchar(H);
	}
	else
	{
		ft_putchar(vi);
	}
}

void	rush(int x, int y)
{
	decla();
	int	i;
	int	j;

	if (x <= 0 || y <= 0)
	{
		write(1, "entre un nombre positif", 23);
	}
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_corners(i, j, x, y, co, H, L, vi);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

char	decla(void)
{
	char H;
	char L;
	char co;
	char vi;

	H = "|";
	L = "-";
	co = "o";
	vi = " ";
	return(H, L, co, vi);

}
