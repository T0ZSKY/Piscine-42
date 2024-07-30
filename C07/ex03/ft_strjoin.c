/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:23:23 by tomlimon          #+#    #+#             */
/*   Updated: 2024/07/30 09:42:09 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcopy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	int		position;
	int		i;
	char	*result;

	total_len = ft_total_len(size, strs, sep);
	result = malloc(total_len);
	if (!result)
		return (NULL);
	position = 0;
	i = 0;
	while (i < size)
	{
		position = ft_copy_str(result, strs[i], position);
		if (i < size - 1)
		{
			position = ft_copy_sep(result, sep, position);
		}
		i++;
	}
	result[position] = '\0';
	return (result);
}

int	ft_copy_str(char *result, char *str, int position)
{
	int	len;

	len = ft_strlen(str);
	ft_strcopy(result + position, str);
	return (position + len);
}

int	ft_copy_sep(char *result, char *sep, int position)
{
	int	sep_len;

	sep_len = ft_strlen(sep);
	ft_strcopy(result + position, sep);
	return (position + sep_len);
}

/*
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
