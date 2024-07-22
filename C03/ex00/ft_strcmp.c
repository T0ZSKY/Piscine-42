/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:18:32 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/22 11:08:34 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	unsigned int	a;
	unsigned int	b;

	i = 0;
	while (s1[i] != 0 || s2[i] != 0)
	{
		a = s1[i];
		b = s2[i];
		if (a != b)
		{
			return (a - b);
		}
		i++;
	}
	return (0);
}
#include <stdio.h>
int	main()
{
	printf("%d", ft_strcmp("Test1","OK"));
}


