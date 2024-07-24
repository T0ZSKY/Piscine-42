/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:52:32 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/24 09:12:23 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	i;

	if (nb == 0)
		return (1);
	else
		return(nb * ft_recursive_factorial(nb - 1));
}

#include <stdio.h>
int	main()
{
	printf("%d", ft_recursive_factorial(5));
}
