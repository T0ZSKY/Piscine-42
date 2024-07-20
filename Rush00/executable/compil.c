/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compil.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 08:36:33 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/20 10:11:16 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void    rush(int x, int y)
{

	char col = '|';
        char lign = '-';
        char co = 'o';
        char vide = ' ';
        int i;
        int j;



	 //si co vide ou negatif on fait rien
        if(x <=0 || y <=0)
        {

        }



        i = 0;
        //ligne
        while(i < y)
        {
		j = 0;
                //colonne
                while(j < x)
                {

			if((i == 0 && j == 0) ||
			(i == 0 && j == x -1)||
			(i == y - 1 && j ==0)||
			(i == y - 1 && j == x -1))
                        {
                                ft_putchar(co);
                      	}
			
				
			
			//pour les petite bordure en haut ou en bas
			else if(i == 0 || i == y - 1)
			{
				ft_putchar(lign);
			}


			else if(j == 0 || j == x - 1)
			{
				ft_putchar(col);
			}


			else
                        {
                                ft_putchar(vide);
                        }


			j++;

                }
		ft_putchar('\n');
		i++;
        }
}


int     main()
{
        rush(5, 5);
}

