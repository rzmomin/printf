#include "ft_printf.h"

int	ft_print_hex(unsigned int n, const char format)
{
	const char	*base;
	char		c;
	int			written;
	int			sub;

	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	written = 0;
	if (n >= 16)
	{
		sub = ft_print_hex(n / 16, format);
		if (sub < 0)
			return (-1);
		written += sub;
	}
	c = base[n % 16];
	if (write(1, &c, 1) == -1)
		return (-1);
	return (written + 1);
}