#include "ft_printf.h"

int	ft_count_chars_uns(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	pointer_len(unsigned long p)
{
	int	i;

	i = 0;
	while (p)
	{
		p = p / 16;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		j;

	if (n <= -2147483648)
		return (ft_strdup("2147483648"));
	if (n < 0)
		n *= -1;
	j = ft_count_chars(n);
	res = (char *)malloc(sizeof(char) * (j + 1));
	if (!res)
		return (NULL);
	if (n == 0)
		res[0] = '0';
	res[j] = '\0';
	while (n)
	{
		res[j - 1] = (n % 10) + '0';
		n = n / 10;
		j--;
	}
	return (res);
}

char	*ft_itoa_uns(unsigned int n)
{
	char			*res;
	unsigned int	j;

	j = ft_count_chars_uns(n);
	res = (char *)malloc(sizeof(char) * (j + 1));
	if (!res)
		return (NULL);
	if (n == 0)
		res[0] = '0';
	res[j] = '\0';
	while (n > 0 && j > 0)
	{
		res[j - 1] = (n % 10) + '0';
		n = n / 10;
		j--;
	}
	return (res);
}

char	*ft_itoa_hex(unsigned long n, int x_type)
{
	char	*res;
	int		j;

	j = pointer_len(n);
	res = (char *)malloc(sizeof(char) * (j + 1));
	if (!res)
		return (NULL);
	if (n == 0)
		res[0] = '0';
	res[j] = '\0';
	while (n)
	{
		if (n % 16 < 10)
			res[j - 1] = (n % 16) + 48;
		else
		{
			if (x_type == 0)
				res[j - 1] = (n % 16) + 87;
			if (x_type == 1)
				res[j - 1] = (n % 16) + 55;
		}
		n = n / 16;
		j--;
	}
	return (res);
}
