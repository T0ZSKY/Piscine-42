/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:33:23 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/23 08:35:45 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		write(1, c, 1);
		i++;
	}
}
