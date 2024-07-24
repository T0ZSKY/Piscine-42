/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:27:33 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/24 16:32:21 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:41:38 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/24 16:33:31 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_fibonacci(int index)
{
    if (index <= 2)
    {
        return (1);
    }
    else
    {
        return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
    }
}
/*
int main()
{
    printf("%d", ft_fibonacci(15));
}
*/


/*
#include <stdio.h>
int	main()
{
	printf("%d", ft_recursive_power(5, 5));
}
*/
