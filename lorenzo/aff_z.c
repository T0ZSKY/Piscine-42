#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i;

	i = 0;
	//printf("Mon code %d", ac);
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (av[1][i])
	{
		if (av[1][i] == 'z')
		{
			write(1, "z", 1);
			return (0);
		}
		i++;	
	}
	return (0);
}