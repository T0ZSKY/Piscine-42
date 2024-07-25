/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:16:47 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/25 11:35:49 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	j;

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
	i = argc - 1;

	while(i > 0)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i--;
	}
	return (0);


}
