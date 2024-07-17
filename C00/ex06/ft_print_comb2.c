/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:47:56 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/17 17:07:18 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void	ft_print_comb2()
{

	char u;
	char d;
	char c;
	char m;

	u = 0;
	while(m <= 9) 
	{
		c = m + 1;
		while(c <= 8) 
		{
			d = c +1;
			while(d <= 9)
			{
				u = d + 1;
				while(u <= 9) 
				{
					write(1, &m, 1);
					write(1, &c, 1);
					write(1, &d, 1);
					write(1, &u, 1);
					u++;
					
				}

				d++;
			}
		c++;
		}
	m++;
	}

}


int main() {

ft_print_comb2();
return 0;
}
