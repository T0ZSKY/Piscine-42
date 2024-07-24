/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:14:48 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/24 16:31:07 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	t;

	t = 1;
	i = 1;
	while (i <= power)
	{
		t = t * nb;
		i++;
	}
	return (t);
}
/*
#include <stdio.h>
int main()
{
	printf("%d", ft_iterative_power(3, 7));
}
*/
