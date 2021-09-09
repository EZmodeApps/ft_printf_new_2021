#include "ft_printf.h"

void	pointer_print(t_flags *flags, int x_type, va_list arg)
{
	unsigned long	p;
	char			*pointer;

	p = (unsigned long)va_arg(arg, void *);
	if (p == 0)
	{
		pointer = "0";
		ft_putstr("0x", flags);
		ft_putstr(pointer, flags);
		return ;
	}
	pointer = ft_itoa_hex(p, x_type);
	ft_putstr("0x", flags);
	ft_putstr(pointer, flags);
	free (pointer);
}

void	hex_print(t_flags *flags, int x_type, va_list arg)
{
	unsigned int	x;
	char			*hex;

	x = va_arg(arg, unsigned int);
	if (x == 0)
	{
		hex = "0";
		ft_putstr(hex, flags);
		return ;
	}
	hex = ft_itoa_hex(x, x_type);
	ft_putstr(hex, flags);
	free (hex);
}
