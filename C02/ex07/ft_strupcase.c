/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:25:25 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/21 10:48:57 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;
	int	min;
	int	maj;

	while(str[i])
	{
		min = (str[i] >= 'a' && str[i] <= 'z' ); 
		if(min)
		{
			str[i] = str[i] - 32;	
		}
	}
	return (str);
}

#include <stdio.h>
int	main()
{
	ft_strupcase("test");
}
