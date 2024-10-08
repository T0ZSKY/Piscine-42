/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:53:01 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/21 10:24:41 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_printable(char *str)
{
	int	print;
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		print = (str[i] >= 32 && str[i] <= 126);
		if (print)
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
int main()
{
	printf("%d", ft_str_is_printable(""));
}
*/
