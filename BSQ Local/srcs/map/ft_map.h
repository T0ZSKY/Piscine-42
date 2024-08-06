/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:26:57 by nopareti          #+#    #+#             */
/*   Updated: 2024/08/06 14:42:35 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
#define FT_MAP_H

#define MAP_SIZE 1024
#define INFO_SIZE 5

char	*ft_read_map(char *file_name);

typedef struct s_map_info
{
	int	nb_lines;
	char	empty_c;
	char	obstacle_c;
	char	full_c;
}			t_map_info;

t_map_info *s_map_info map_info;

#endif
