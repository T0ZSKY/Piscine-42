/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:54:28 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/22 18:26:07 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	j = 0;
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (str[i] == to_find[j])
			{
				i++;
				j++;
			}
			i = i - 2;
			if (to_find[j] == '\0')
				return (str + i);
		}
		i++;
	}
	return (0);
}
