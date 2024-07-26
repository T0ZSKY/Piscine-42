/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 08:47:46 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/26 09:17:12 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *st)
{
	int	j;

	j = 0;
	while(st[j])
	{
		j++;
	}
	
	return (j);
}


void	ft_search_and_replace(char *str, char *letter, char *replace)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while(str[i])
	{
		if (str[i] == letter[0])
		{
			str[i] = replace[0];
		}
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	

	if(ft_strlen(argv[2]) > 1 || ft_strlen(argv[3]) > 1)
	{
		write(1, "\n", 1);
		return (0);
	}

	ft_search_and_replace(argv[1], argv[2], argv[3]);
	write(1, "\n", 1);
}	
