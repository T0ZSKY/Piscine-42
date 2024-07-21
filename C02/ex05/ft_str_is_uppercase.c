/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:06:36 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/21 08:52:01 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	uppercase;
	int	i;

	i = 0;
	while (str[i])
	{
		uppercase = (str[i] >= 'A' && str[i] <= 'Z');
		if (uppercase)
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
/*
#include <stdio.h>
int	main()
{
	printf("%d", ft_str_is_uppercase("TEST"));
}
*/
