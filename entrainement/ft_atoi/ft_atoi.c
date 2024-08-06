
int ft_atoi(char *src)
{
	int	i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;

	while (src[i] == 32 || (src[i] >= 9 && src[i] <= 13))
	{
		i++;
	}

	if (src[i] == '-' || src[i] == '+')
	{
		if (src[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}

	while (src[i] >= '0' && src[i] <= '9')
	{
		result = result * 10 + (src[i] - '0');
		i++;
	}

	return (result * sign);

}
#include <stdio.h>


int main() {
    char str1[] = "   -1234abc";
    char str2[] = "5678";
    char str3[] = "+42";

    printf("%d\n", ft_atoi(str1)); // Affiche -1234
    printf("%d\n", ft_atoi(str2)); // Affiche 5678
    printf("%d\n", ft_atoi(str3)); // Affiche 42

    return 0;
}


