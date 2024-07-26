/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:14:48 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/26 21:29:14 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	t;
	int s;
	s = 1;

	if (power == 1)
	{
		return (2);
	}
	if (nb < 0 && power > 1)
		s *= -1;
		nb = -nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	t = 1;
	while (power > 0)
	{
		t *= nb;
		power--;
	}
	return (t * s);
}

