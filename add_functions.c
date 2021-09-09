#include "ft_printf.h"

void	ft_putchar(char c, t_flags *flags)
{
	write(1, &c, 1);
	flags->str_len++;
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, t_flags *flags)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
		flags->str_len += 1;
	}
}

int	ft_count_chars(int n)
{
	int		i;

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

char	*ft_strdup(const char *s1)
{
	int		i;
	int		length;
	char	*copy;

	i = 0;
	length = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * (length + 1));
	if (copy)
	{
		while (s1[i])
		{
			copy[i] = s1[i];
			i++;
		}
		copy[i] = '\0';
		return (copy);
	}
	else
		return (NULL);
}
