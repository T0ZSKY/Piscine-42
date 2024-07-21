/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:53:01 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/21 10:03:49 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if(str[i] > 32 || str[i] < 126)
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

#include <stdio.h>
int main()
{
	printf("%d", ft_str_is_printable("\t"));
}
