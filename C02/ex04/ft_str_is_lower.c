/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:58:14 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/20 18:04:27 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int lowercase;
	int i;

	i = 0;
	while(str[i])
	{
		lowercase = (str[i] >= 'a' && str[i] <= 'z');

		if(lowercase)
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
int main()
{
	printf("%d", ft_str_is_lowercase("teFDt"));
}
*/
