/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:47:56 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/18 08:57:13 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_results(a, b, c, d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;
	
	a = '0';
	while (a <= '9')
	{	
		b = '0';
		while (b <= '9')
		{	
			c = a;
			while (c <= '9')
			{
				if (c == a)
					d = b + 1;
				else
					d = '0';
				while (d <= '9')
				{			
					ft_write_results(a, b, c, d);
					if (!(a == '9' && b == '8' && c == '9' && d == '9'))
						write(1, ", ", 2);
					d++;
				}
				c++;
			}
			b++;
		}
		a++;
	}
}
