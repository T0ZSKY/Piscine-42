#include <unistd.h>

void	ft_putnbr(int nb)
{
	char c;

	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return;
		}
		write(1, "-", 1);
		nb = -nb;
		
	}

	

	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	c = nb % 10 + '0';
	write(1, &c, 1);
}


int main()
{
	ft_putnbr(2147483647);
}