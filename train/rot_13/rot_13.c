/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:47:52 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/26 11:13:50 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rot_13(char *src)
{
	int	i;
	i = 0;

	while(src[i])
	{
		if(src[i] >= 'a' && src[i] < 'n')
		{
			src[i] = src[i] + 13;
			write(1, &src[i], 1);
		}

		else if (src[i] >= 'A' && src[i] < 'N')
		{
			src[i] = src[i] + 13;
			write(1, &src[i], 1);
		}
		
		else if (src[i] >= 'n' && src[i] <= 'z')
		{
			src[i] = src[i] - 13;
			write(1, &src[i], 1);
		}

		else if(src[i] >= 'N' && src[i] <= 'Z')
		{
			src[i] = src[i] - 13;
			write(1, &src[i], 1);
		}
		else
			write(1, &src[i], 1);
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

	ft_rot_13(argv[1]);
	write(1, "\n", 1);
}
