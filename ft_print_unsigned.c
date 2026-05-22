#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	char	c;
	int		written;
	int		sub;

	written = 0;
	if (n >= 10)
	{
		sub = ft_print_unsigned(n / 10);
		if (sub < 0)
			return (-1);
		written += sub;
	}
	c = (char)(n % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (written + 1);
}