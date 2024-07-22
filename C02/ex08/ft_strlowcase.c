/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:19:22 by tolimon           #+#    #+#             */
/*   Updated: 2024/07/21 14:05:06 by tolimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strlowcase(char *str)
{
	int	i;
	int	maj;

	i = 0;
	while (str[i])
	{
		maj = (str[i] >= 'A' && str[i] <= 'Z');
		if (maj)
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
/*
int main()
{
        char    src[7] = "TEST";
        ft_strlowcase(src);
        printf("%s", src);

}
*/
