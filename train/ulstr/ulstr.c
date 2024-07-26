/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:36:07 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/26 10:43:32 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ulstr(char *src)
{
	int	i;

	i = 0;
	while(src[i])
	{
		if(src[i] >= 'a' && src[i] <= 'z')
		{
			src[i] = src[i] - 32;
			write(1, &src[i], 1);
		}

		else if(src[i] >= 'A' && src[i] <= 'Z')
		{
			src[i] = src[i] + 32;
			write(1, &src[i], 1);
		}

		else
			write(1, &src[i], 1);
		i++;
	}
	
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_ulstr(argv[1]);
	write(1, "\n", 1);
}
