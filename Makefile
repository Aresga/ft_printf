CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/

SRC = ft_printf.c \
		$(SRC_DIR)ft_putchar.c \
		$(SRC_DIR)ft_putstr.c \
		$(SRC_DIR)ft_putnbr_base.c \
		$(SRC_DIR)ft_putnbr_u.c \
		$(SRC_DIR)ft_print_format.c \
		$(SRC_DIR)ft_putptr.c \
		$(SRC_DIR)ft_strlen.c \
		$(SRC_DIR)ft_putnbr.c 

HEADER = ./ft_printf.h

OBJS = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(NAME) created and indexed"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	@rm -f $(OBJS)
	@echo "Object files deleted."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re