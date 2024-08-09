
#include <stdlib.h>
#include <stdio.h>
char	*ft_strdup(char *src)
{
	int	taille;
	char *dupli;
	int i;
	taille = 0;
	i = 0;

	while (src[taille])
	{
		taille++;
	}
	dupli = malloc(sizeof(char) * taille + 1);
	
	while (src[i])
	{
		dupli[i] = src[i];
		i++;
	}
	dupli[i] = '\0';
	
	return dupli;
}

int main()
{
	printf("%s", ft_strdup("test"));
}