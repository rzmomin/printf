NAME      = libftprintf.a
CC        = cc
CFLAGS    = -Wall -Wextra -Werror
AR        = ar rcs
RM        = rm -f

SRCS      = ft_printf.c \
            ft_print_char.c \
            ft_print_str.c \
            ft_print_nbr.c \
            ft_print_unsigned.c \
            ft_print_hex.c \
            ft_print_ptr.c \
            ft_print_percent.c

OBJS      = $(SRCS:.c=.o)
HEADER    = ft_printf.h

all:      $(NAME)

$(NAME):  $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o:      %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:   clean
	$(RM) $(NAME)

re:       fclean all

.PHONY:   all clean fclean re