/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:37:12 by tolimon           #+#    #+#             */
/*   Updated: 2024/08/01 10:15:38 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *src)
{
    int i;

    i = 0;
    while(src[i])
    {
        i++;
    }
    return i;
}

int main(int argc, char *argv[])
{
    int i;
    int max;
    char temp;

    i = 0;
    if(argc != 2)
    {
        write(1, "\n", 1);
        return 1;
    }
    max = ft_strlen(argv[1]);
    while(i < max / 2)
    {
        temp = argv[1][i];
        argv[1][i] = argv[1][max - i - 1];
        argv[1][max - i - 1] = temp;
        i++;
    }
    i = 0;
    while(argv[1][i])
    {
        write(1, &argv[1][i], 1);
        i++;
    }
    write(1, "\n", 1);
}
