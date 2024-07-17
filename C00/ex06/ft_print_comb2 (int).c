/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:47:56 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/17 18:58:06 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void	ft_print_comb2()
{
	char temp;
	int a;
	int b;
	int c;
	int d;

	a = 0;
	b = 0;
	c = 0;
	d = 0;
	while(a <= 9) 
	{
	
		b = 0;	
		while(b <= 9) 
		{
		c = b + 1;
		
			
			while(c <= 9)
			{
			
				d = c + 1;			
				while(d <= 9) 
				{
					temp = a + '0';
					write(1, &temp, 1);
					temp = b + '0';
					write(1, &temp, 1);
					write(1, " ",1);
					temp = c + '0';
					write(1, &temp, 1);
					temp = d + '0';
                                        write(1, &temp, 1);
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


int main() {

ft_print_comb2();

}
