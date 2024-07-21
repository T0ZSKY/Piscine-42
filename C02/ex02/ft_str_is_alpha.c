/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:09:02 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/21 08:30:09 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	maj;
	int	min;
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		min = (str[i] >= 'a' && str[i] <= 'z');
		maj = (str[i] >= 'A' && str[i] <= 'Z');
		if (maj || min)
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
	printf("%d", ft_str_is_alpha("tEsT"));
}
*/
