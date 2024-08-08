

int ft_atoi(char *nb)
{
	int	i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;


	while (nb[i] == 32 || (nb[i] >= 9 && nb[i] <= 13))
	{
		i++;
	}

	while (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			sign = sign * -1;
		i++;
	}

	while(nb[i] >= '0' && nb[i] <= '9')
	{
		result = result * 10 + (nb[i] - '0');
		i++;
	}

	return (result * sign);

}
#include <stdio.h>
int main()
{
	printf("%d", ft_atoi("53"));
}