/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:14:50 by tolimon           #+#    #+#             */
/*   Updated: 2024/08/05 11:10:43 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

typedef int	t_bool;

# define TRUE	1
# define FALSE	0
# define EVEN(x)	((x % 2) == 1 ? 0 : 1)
# define EVEN_MSG	"I have an even numbers of arguments."
# define ODD_MSG		"I have an odd numbers of arguments."
# define SUCCESS		0

#endif
