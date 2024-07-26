/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 08:30:44 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/26 08:42:41 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


void	ft_alpha(char *src)
{
	int	i;
	int	index;
	int	n;
	
	i = 0;
	index = 0;
	n = 0;
	while(src[i])
	{
		index = 0;
		n = 0;
		if(src[i] >= 'A' && src[i] <= 'Z')
		{
			index = src[i] - 65;
		}

		if(src[i] >= 'a' && src[i] <= 'z')
		{
			index = src[i] - 96;
		}

		else
		{
			write(1, &src[i], 1);
		}

		while(index > n)
		{
			write(1, &src[i], 1);
			n++;
		}


		i++;
	}
}


int	main(int argc, char *argv[])
{
	if(argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	ft_alpha(argv[1]);
	write(1, "\n", 1);
}


