#include "ft_printf.h"
#include <stdio.h>
void	what_type(char str, t_flags *flag, va_list arg)
{
	int	x_type;

	x_type = 0;
	if (str == 'c')
		char_print(flag, arg);
	if (str == 's')
		str_print(flag, arg);
	if (str == 'd' || str == 'i')
		int_print(flag, arg);
	if (str == '%')
		ft_putchar('%', flag);
	if (str == 'p')
		pointer_print(flag, x_type, arg);
	if (str == 'u')
		unsigned_int_print(flag, arg);
	if (str == 'x')
		hex_print(flag, x_type, arg);
	if (str == 'X')
	{
		x_type = 1;
		hex_print(flag, x_type, arg);
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	t_flags	flags;
	va_list	arg;

	i = 0;
	va_start(arg, str);
	flags.str_len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			flags.int_minus = 0;
			i++;
			what_type(str[i], &flags, arg);
		}
		else
			ft_putchar(str[i], &flags);
		i++;
	}
	va_end(arg);
	return (flags.str_len);
}

int main()
{
    char *s1 = "hello fucking c";
    char z = 'a';
    int d = -2147483648;
    unsigned int ii = 789567;
    unsigned int uns = 4294967295;
    unsigned int unss = 4242;
    char *p_c = "i hate c";
    // int *p_i = 6666666;
    char *p_null = NULL;
    int a;
    int b;

    a = printf("ORIGINAL: he %c %s %d %i %u %% %x %X hello\n", z, s1, d, ii, uns, s1, s1);
    b = ft_printf("MY      : he %c %s %d %i %u %% %x %X hello\n", z, s1, d, ii, uns, s1, s1);
    printf("orlen: %d\nmylen: %d\n\n", a, b);
}
