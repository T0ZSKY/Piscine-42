/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:25:25 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/21 11:07:10 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;
	int	min;

	i = 0;
	while(str[i])
	{
		min = (str[i] >= 'a' && str[i] <= 'z' ); 
		if(min)
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}


int main()
{
	char	src[7] = "test";
	ft_strupcase(src);
	printf("%s", src);

}
