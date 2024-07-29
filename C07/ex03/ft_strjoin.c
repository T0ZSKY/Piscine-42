/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:21:19 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/29 15:54:53 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcopy(char *dest, char *src)
{
	int i;

	i = 0;

	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_strlen(char *src)
{
	int	o;

	o = 0;
	while(src[0])
	{
		o++;
	}
	return (o);
}	

char	*ft_strjoin(int size, char **strs, char *sep)
{

	if(size <= 0)
		return 0;

	int	i;
	while()


}
