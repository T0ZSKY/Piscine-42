

int ft_atoi(char *nb)
{
	int i;
	int result;
	int sign;

	i = 0;
	sign = 1;
	result = 0;


	if(nb[i] == '-')
	{
		sign = -1;
		i++;
	}
	
	while(nb[i] >= '0' && nb[i] <= '9')
	{
		result = result * 10 + nb[i] - '0';
		i++;
	}
	return (result * sign);
}
#include <stdio.h>
int main()
{
	printf("%d", ft_atoi("-42"));
}