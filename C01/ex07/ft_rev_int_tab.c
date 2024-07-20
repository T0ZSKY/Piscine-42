/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:24:42 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/18 18:47:38 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temps;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		temps = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temps;
		i++;
	}	
}
/*int main()
{
        int tab[3];
        int size;
        size = 3;
        tab[0] = 1;
        tab[1] = 2;
        tab[2] = 3;
        ft_rev_int_tab(tab, size);
	printf("%d", tab[2]);
}*/
