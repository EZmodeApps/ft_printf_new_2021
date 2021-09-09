#include "ft_printf.h"

void	int_print(t_flags *flags, va_list arg)
{
	int		number;
	char	*num;

	number = va_arg(arg, int);
	if (number < 0)
		flags->int_minus = 1;
	num = ft_itoa(number);
	if (flags->int_minus == 1)
		ft_putchar('-', flags);
	ft_putstr(num, flags);
	free (num);
}

void	unsigned_int_print(t_flags *flags, va_list arg)
{
	unsigned int	number;
	char			*num;

	number = va_arg(arg, unsigned int);
	num = ft_itoa_uns(number);
	ft_putstr(num, flags);
	free (num);
}

void	str_print(t_flags *flag, va_list arg)
{
	char	*s;

	s = va_arg(arg, char *);
	if (!s)
		s = "(null)";
	ft_putstr(s, flag);
}

void	char_print(t_flags *flags, va_list arg)
{
	unsigned char	c;

	c = (unsigned char)va_arg(arg, int);
	ft_putchar(c, flags);
}
