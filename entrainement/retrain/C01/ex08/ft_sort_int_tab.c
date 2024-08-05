void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < size)
	{
		while (j < size - 1)
		{
			if (tab[j + 1] < tab[j])
			{
				tmp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = tmp;
				j = 0;
			}
			else
				j++;
		}
		i++;
	}
}
