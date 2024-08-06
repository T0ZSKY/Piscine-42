#include <unistd.h>
#include <stdio.h>

void ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

int ft_atoi(char *str)
{
	int result;
	int sign;
	int i; 

	i = 0;
	sign = 1;
	result = 0;

	while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')	
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result += (str[i] - 48);
		i++;
	}
	return (result * sign);
}

int main(int ac, char **av)
{
	int a;
	int b;
 
	a = ft_atoi(av[1]);
	b = ft_atoi(av[2]);
	printf("Value of a : %d\n", a);
	printf("Value of b : %d\n", b);
	ft_swap(&a,&b);
	printf("Value of a after : %d\n", a);
	printf("Value of b after: %d\n", b);

}