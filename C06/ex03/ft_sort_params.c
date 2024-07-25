/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:39:42 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/25 11:59:39 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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


int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned int	b;
	unsigned int	a;

	i = 0;
	while (s1[i] != 0 || s2[i] != 0)
	{
		a = s1[i];
		b = s2[i];
		if (a != b)
		{
			return (a - b);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	max;

	i = 0;
	max = argc;

}
