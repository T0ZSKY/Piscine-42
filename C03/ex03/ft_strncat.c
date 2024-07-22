/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:52:09 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/22 16:44:52 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				dest_taille;

	dest_taille = ft_strlen(dest);
	i = 0;
	while (src[i] && i < nb)
	{
		dest[dest_taille + i] = src[i];
		i++;
	}
	dest[dest_taille + i] = '\0';
	return (dest);
}
