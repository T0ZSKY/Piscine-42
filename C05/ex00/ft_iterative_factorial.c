/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:42:29 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/26 21:27:22 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	factorial;

	if (nb < 0)
	{
		return (0);
	}
	if (nb == 0)
	{
		return (1);
	}
	i = 1;
	factorial = 1;
	while (i <= nb)
	{
		factorial = factorial * i;
		i++;
	}
	return (factorial);
}
/*
#include <stdio.h>
int	main()
{
	printf("%d", ft_iterative_factorial(0));
}
*/
