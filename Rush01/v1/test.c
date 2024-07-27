/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 09:50:30 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/27 16:04:13 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int    ft_strlen(char *src)
{
    int o;
    o = 0;

    while (src[o])
    {
        o++;
    }
    return (o);
}

int	ft_check(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (!(str[i] >= '1' && str[i] <= '4'))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int main(int argc, char *argv[])
{
    // Gestion des erreurs
    if (argc != 2)
    {
        write(1, "Error", 5);
        write(1, "\n", 1);
        return 1;
    }

    if (ft_strlen(argv[1]) != 16)
    {
        write(1, "ERROR", 5);
        return (1);
    }

    if (ft_check(argv[1]) == 1)
    {
        write(1, "ERROR", 5);
        return (1);
    }

    // Gestion du tableau
    char tab[6][6] = {
        {' ', '1', '1', '1', '1', ' '},
        {'1', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '1'},
        {' ', '1', '1', '1', '1', ' '}
    };

    int f = 0;
    int g = 0;
    while (g < 6)
    {
        int b = 0;
        while (b < 6)
        {
            if (tab[g][b] == '1')
            {
                if (argv[1][f] != '\0')
                {
                    tab[g][b] = argv[1][f];
                    f++;
                }
                else
                {
                    break;
                }
            }
            b++;
        }
        g++;
    }
//condition pour remplir le centre du jeu
    int z = 0;

    while (z < 6)
    {
        if (tab[0][z] == '4')
        {
            tab[1][z] = '1';
            tab[2][z] = '2';
            tab[3][z] = '3';
            tab[4][z] = '4';
        }
	else if (tab[5][z] == '4')
	{
		tab[1][z] = '4';
           	tab[2][z] = '3';
            	tab[3][z] = '2';
            	tab[4][z] = '1';

	}
	else if(tab[0][z] == '1')
	{
		tab[1][z] = '4';
	}
	else if(tab[5][z] == '1')
	{
		tab[4][z] = '4';
	}
        z++;
    }
//fin condition pour le centre du jeu
    write(1, "\n", 1);

    // Imprime le tableau
    int i = 0;
    while (i < 6)
    {
        int j = 0;
        while (j < 6)
        {
            write(1, &tab[i][j], 1);
            write(1, " ", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }

    return 0;
}
