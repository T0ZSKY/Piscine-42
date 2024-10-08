/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:24:31 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/21 08:31:02 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	nombre;
	int	i;

	i = 0;
	while (str[i])
	{
		nombre = (str[i] >= '0' && str[i] <= '9');
		if (nombre)
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
