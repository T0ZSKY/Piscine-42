/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:15:26 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/29 11:58:52 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int *ft_range(int min, int max)
{
    int *tab;
    int i;

    if (min >= max) 
        return (NULL);

    tab = malloc(sizeof(int) * (max - min));

    i = 0;
    while (min < max)
    {
        tab[i] = min;
	min ++;
	i++;
    }

    return tab;
}
