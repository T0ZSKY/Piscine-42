/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledupon <aledupon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:35:23 by tomlimon          #+#    #+#             */
/*   Updated: 2024/07/28 10:44:55 by aledupon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <unistd.h>

int	check_args(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	if (ft_strlen(argv[1]) != 31)
		return (0);
	if (ft_check(argv[1]) == 1)
		return (0);
	return (1);
}
