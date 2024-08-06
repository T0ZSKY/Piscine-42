/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:08:31 by tomlimon          #+#    #+#             */
/*   Updated: 2024/08/05 15:24:12 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int *check_map(char *files)
{
	char *read;
	
	//lire le fichier map

	int i = 0;
	while (read[i] != '\0')
	{
		//verifier si la ligne est valide
		if(read[i] != "o" || read[i] != "." || read[i] != "\n")
		{
			return (1);
		}
		i++;
	}
	return 0;
}


int main()
{
	char *read;
	
	//boucle pour lire le fichier map est verifier si il est valide
	while (read = read_map())
	{
		if (check_map(read))
		{
			//trouver le plus grand carré
			//afficher le plus grand carré
		}
		else
		{
			write(2, "map error\n", 10);
		}
	}
	
}