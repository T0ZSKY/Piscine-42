#include <stdlib.h>

char *ft_strcopy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

int ft_strlen(char *src)
{
	int o;

	o = 0;
	while (src[o])
	{
		o++;
	}
	return o;
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	if (size <= 0)
		return NULL;

	int i;
	int total_len;
	int sep_len;
	char *result;
	int pos;

	i = 0;
	total_len = 0;
	sep_len = ft_strlen(sep);

	while (i < size)
	{
		total_len = total_len + ft_strlen(strs[i]);
		i++;
	}

	if (size > 1)
		total_len += (size - 1) * sep_len;
	total_len += 1;

	result = malloc(total_len);
	if (!result)
		return NULL;

	i = 0;
	pos = 0;

	while (i < size)
	{
		int len;

		len = ft_strlen(strs[i]);
		ft_strcopy(result + pos, strs[i]);
		pos += len;

		if (i < size - 1)
		{
			ft_strcopy(result + pos, sep);
			pos += sep_len;
		}

		i++;
	}

	result[pos] = '\0';

	return result;
}
#include <stdio.h>
int main()
{
	char *strs[] = {"Hello", "World", "42"};
	char *sep = "_";
	char *result = ft_strjoin(3, strs, sep);
	printf("%s\n", result);
	free(result);
}