/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 08:58:42 by tolimon           #+#    #+#             */
/*   Updated: 2024/08/01 09:18:51 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	if(argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	while(argv[1][i])
	{
		if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
		{
			argv[1][i] = argv[1][i] - 32;
		}
		else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			argv[1][i] = argv[1][i] + 32;
		}
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
}
