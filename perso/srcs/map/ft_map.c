/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:38:37 by nopareti          #+#    #+#             */
/*   Updated: 2024/08/06 14:43:18 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_map.h"

char	*ft_read_map(char *file_name)
{
	int file;
	int bytes_info;
	int bytes_map;
	char *str_info;
	char *str_map;
	t_map_info *s_map_info map_info;

	bytes_info = 0;
	bytes_map = 0;
	file = open(file_name, O_RDWR);
	str_info = malloc(INFO_SIZE);
	str_map = malloc(MAP_SIZE);
	bytes_info = read(file, str_info, INFO_SIZE + 1);
	bytes_map = read(file, str_map, MAP_SIZE - 1);
	str_info[bytes_info] = '\0';
	str_map[bytes_map] = '\0';
	map_info->
	close(file);
	return (str_map);
}
