/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:20:05 by nopareti          #+#    #+#             */
/*   Updated: 2024/08/06 13:59:59 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "map/ft_map.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	char *map;
	map = ft_read_map(argv[1]);
	printf("%s", map);
	free(map);
	return (0);
}
