void ft_rev_int_tab(int *tab, int size)
{
	int	j;
	int i;
	int temp;

	j = size - 1;
	i = 0;
	temp = 0;
	while(i < j)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		i++;
		j--;
	}
}