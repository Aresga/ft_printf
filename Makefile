CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c

HEADER = ft_printf.h

OBJS = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(NAME) created and indexed"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@ -Iinclude

clean:
	@rm -f $(OBJS)
	@echo "Object files deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re