/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimete_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:42:07 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/29 12:05:57 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int *ft_ultimate_range(int **range, int min, int max)
{
    
    int i;

    if (min >= max)
        return (NULL);

   *range = malloc (sizeof(int) * (max - min));

   if(!range)
   {
	return (0);
   }


    i = 0;
    while (min < max)
    {
	(*range)[i] = min;
	min++;
        i++;
    }

    return i; 
}
