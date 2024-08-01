/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:16:33 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/23 17:27:39 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_whitespace(int *i, char *str);

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	result;

	
	result = 0;
	i = 0;
	ft_whitespace(&i, str);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * j);
}

void	ft_whitespace(int *i, char *str)
{
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		*i = *i + 1;
}
/*
#include <stdio.h>

int	ft_atoi(char *str);

int	main(void)
{
	printf("42:%d\n", ft_atoi("  \n  42t4457"));
	printf("-42:%d\n", ft_atoi(" --+-42sfs:f545"));
	printf("0:%d\n", ft_atoi("\0 1337"));
	printf("0:%d\n", ft_atoi("-0"));
	printf("0:%d\n", ft_atoi(" - 1 3 2 5 6 3 2 1 6 7"));
	printf("-1325632167:%d\n", ft_atoi("-1325632167"));
	printf("-100:%d\n", ft_atoi("-100"));
	printf("min:%d\n", ft_atoi("\t---+2147483648"));
	printf("max:%d\n", ft_atoi("\v2147483647"));
}
*/
