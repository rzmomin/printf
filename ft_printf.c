#include "ft_printf.h"

static int	dispatch(char spec, va_list ap)
{
	if (spec == 'c')
		return (ft_print_char(va_arg(ap, int)));
	if (spec == 's')
		return (ft_print_str(va_arg(ap, char *)));
	if (spec == 'p')
		return (ft_print_ptr((unsigned long)va_arg(ap, void *)));
	if (spec == 'd' || spec == 'i')
		return (ft_print_nbr(va_arg(ap, int)));
	if (spec == 'u')
		return (ft_print_unsigned(va_arg(ap, unsigned int)));
	if (spec == 'x' || spec == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), spec));
	if (spec == '%')
		return (ft_print_percent());
	return (0);
}

static int	put_raw(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;
	int		sub;

	if (!format)
		return (-1);
	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			sub = dispatch(format[++i], ap);
		else
			sub = put_raw(format[i]);
		if (sub < 0)
			return (va_end(ap), -1);
		count += sub;
		i++;
	}
	va_end(ap);
	return (count);
}