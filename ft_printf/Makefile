.PHONY: clean

NAME = libftprintf.a
MAND = ft_printf.c MDR/ft_putchar_fd.c MDR/ft_putnbr_fd.c MDR/ft_putstr_fd.c MDR/ft_puthex.c MDR/ft_putu.c
BNS = BNS/ft_bonus.c BNS/ft_printf.c MDR/ft_putchar_fd.c MDR/ft_putnbr_fd.c MDR/ft_putstr_fd.c MDR/ft_puthex.c MDR/ft_putu.c
OBJ = $(MAND:%.c=%.o)
B_OBJ = $(BNS:%.c=%.o)
CC = cc
CFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAG) -c $< -o $@

bonus: $(B_OBJ)
	ar -rc $(NAME) $(B_OBJ)

BNS/%.o: BNS/%.c ft_printf.h
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJ) $(B_OBJ)
fclean: clean
	rm -f libftprintf.a
re: fclean all