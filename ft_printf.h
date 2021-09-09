#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int		int_minus;
	int		str_len;
}				t_flags;

int		ft_printf(const char *str, ...);
void	what_type(char str, t_flags *flag, va_list arg);
void	ft_putchar(char c, t_flags *flags);
int		ft_strlen(const char *s);
void	ft_putstr(char *str, t_flags *flags);
int		ft_count_chars(int n);
char	*ft_strdup(const char *s1);
int		ft_count_chars_uns(unsigned int n);
int		pointer_len(unsigned long p);
char	*ft_itoa(int n);
char	*ft_itoa_uns(unsigned int n);
char	*ft_itoa_hex(unsigned long n, int x_type);
void	int_print(t_flags *flags, va_list arg);
void	unsigned_int_print(t_flags *flags, va_list arg);
void	str_print(t_flags *flag, va_list arg);
void	char_print(t_flags *flags, va_list arg);
void	pointer_print(t_flags *flags, int x_type, va_list arg);
void	hex_print(t_flags *flags, int x_type, va_list arg);

#endif
