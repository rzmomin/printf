#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	unsigned int	u;
	int				count;
	int				sub;

	count = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count++;
		u = (unsigned int)(-(long)n);
	}
	else
		u = (unsigned int)n;
	sub = ft_print_unsigned(u);
	if (sub < 0)
		return (-1);
	return (count + sub);
}