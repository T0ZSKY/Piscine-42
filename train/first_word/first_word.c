/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:22:56 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/25 15:00:04 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_test(char *src)
{
	int i;

	i = 0;
	while(src[i])
	{
		if(src[i] == 32 || src[i] == 9)
			break;

		write(1, &src[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int     main(int argc, char *argv[])
{
        int     i;

        i = 0;
        if(argc != 2)
        {
                write(1, "\n", 1);
                return (0);
        }

        ft_test(argv[1]);
	return(0);
}

