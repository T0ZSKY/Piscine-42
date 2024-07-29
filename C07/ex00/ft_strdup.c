/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:45:38 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/29 09:30:50 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	o;

	o = 0;
	while (src[o])
	{
		o++;
	}
	return (o);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		src_len;
	char	*dest;

	i = 0;
	dest = malloc (sizeof * dest * (ft_strlen(src) + 1));
	if (dest)
	{
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
/*
#include <stdio.h>
int	main()
{

	printf("%s", ft_strdup("hello"));
}
*/
