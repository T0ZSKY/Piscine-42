/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:37:33 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/25 14:07:22 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
void	ft_putstr(char *str)
{
	int j;

	j = 0;
	while(str[j])
	{
		write(1, &str[j], 1);
		j++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	index;
	int	a;

	i = 0;
	a = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	while(argv[1][i])
	{
		index = 0;
		a = 0;
		if(argv[1][i] >= 65 && argv[1][i] <= 90 )
			index = argv[1][i] - 65;
		if(argv[1][i] >=97 && argv[1][i] <= 122)
			index = argv[1][i] - 97;

		while(a <= index)
		{
			write(1, &argv[1][i], 1);
			a++;
		}
		i++;
	}
	write(1, "\n", 1);
	
}
