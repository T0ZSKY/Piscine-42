/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:23:23 by tomlimon          #+#    #+#             */
/*   Updated: 2024/07/30 10:15:10 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	len;

	len = 0;
	while (src[len])
	{
		len++;
	}
	return (len);
}

void	ft_strcopy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;
	int	sep_len;

	total_len = 0;
	i = 0;
	sep_len = ft_strlen(sep);
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	if (size > 1)
	{
		total_len += (size - 1) * sep_len;
	}
	return (total_len + 1);
}

void	ft_copy_strings(int size, char **strs, char *sep, char *result)
{
	int	i;
	int	position;
	int	str_len;
	int	sep_len;

	position = 0;
	sep_len = ft_strlen(sep);
	i = 0;
	while (i < size)
	{
		str_len = ft_strlen(strs[i]);
		ft_strcopy(result + position, strs[i]);
		position += str_len;
		if (i < size - 1)
		{
			ft_strcopy(result + position, sep);
			position += sep_len;
		}
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	char	*result;

	total_len = ft_total_len(size, strs, sep);
	result = malloc(total_len);
	if (!result)
		return (NULL);
	ft_copy_strings(size, strs, sep, result);
	result[total_len - 1] = '\0';
	return (result);
}
/*
#include <stdio.h>
int	main()
{
	char *strs[] = {"Hello", "World", "42"};
	char *sep = "__";
	char *result = ft_strjoin(3, strs, sep);
	printf("%s\n", result);
	free(result);
	return 0;
}
*/
