#include <unistd.h>

int main(int argc, char *argv[])
{
	char tab[256] = {};
	int	i;

	i = 0;
	while(argv[1][i])
	{
		if (tab[(unsigned char)argv[1][i]] == 0)
		{
			write(1, &argv[1][i], 1);
			tab[(unsigned char)argv[1][i]] = 1;
		}
		i++;
	}
	i = 0;
	while(argv[2][i])
	{
		if (tab[(unsigned char)argv[2][i]] == 0)
		{
			write(1, &argv[2][i], 1);
			tab[(unsigned char)argv[2][i]] = 1;
		}
		i++;
	}
	return argc;
}