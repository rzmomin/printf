#include "ft_printf.h"

int	ft_print_char(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if (write(1, &ch, 1) == -1)
		return (-1);
	return (1);
}