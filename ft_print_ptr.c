#include "ft_printf.h"

static int	put_hex_long(unsigned long n)
{
	const char	*base = "0123456789abcdef";
	char		c;
	int			written = 0;
	int			sub;

	if (n >= 16)
	{
		sub = put_hex_long(n / 16);
		if (sub < 0)
			return (-1);
		written += sub;
	}
	c = base[n % 16];
	if (write(1, &c, 1) == -1)
		return (-1);
	return (written + 1);
}

int	ft_print_ptr(unsigned long ptr)
{
	int	sub;

	if (ptr == 0)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	sub = put_hex_long(ptr);
	if (sub < 0)
		return (-1);
	return (2 + sub);
}