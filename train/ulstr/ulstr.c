/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:09:21 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/25 14:19:45 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;

	if(argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	
	while(argv[1][i])
	{
		if(argv[1][i] >= 65 && argv[1][i] <= 90)
		{
			argv[1][i] = argv[1][i] + 32;
			write(1, &argv[1][i], 1);
		}

		else if(argv[1][i] >= 97 && argv[1][i] <= 122)
		{
			argv[1][i] = argv[1][i] - 32;
			write(1, &argv[1][i], 1);
		}
		else
		{
			write(1, &argv[1][i], 1);
		}
		i++;

	}
	write(1, "\n", 1);
}
