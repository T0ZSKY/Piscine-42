#include <stdlib.h>
#include <unistd.h>

int	*ft_range(int min, int max)
{
	int	i;
	int *tab;
	i = 0;
	tab = malloc(sizeof(int) * (max - min));
	while(min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}

	return tab;

}
#include <stdio.h>

int *ft_range(int min, int max);

int	main(void)
{
	int *range;

	range = ft_range(0, 5);
	printf("%d, %d, %d, %d, %d\n", range[0], range[1], range[2], range[3], range[4]);
	
	
}