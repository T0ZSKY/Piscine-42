/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:05:49 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/22 10:46:06 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;
	unsigned int	a;
	unsigned int	b;

	i =0;
	while(s1[i] != '\0' && s2[i] != '\0' && i < n)
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
/*
#include <stdio.h>
int     main()
{
	unsigned int n = 4;
        printf("%d", ft_strncmp("ateo","ateq", n));
}
*/

