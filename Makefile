CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/

#LIBFT_DIR = ./libft/

#LIBFT = $(LIBFT_DIR)libft.a

SRC = ft_printf.c \
		$(SRC_DIR)ft_putchar.c \
		$(SRC_DIR)ft_putstr.c \
		$(SRC_DIR)ft_putnbr_base.c \
		$(SRC_DIR)ft_putnbr_u.c \
		$(SRC_DIR)ft_print_format.c \
		$(SRC_DIR)ft_putptr.c \
		$(SRC_DIR)ft_strlen.c

#INCLUDE_DIR = ./include/

HEADER = ./ft_printf.h

OBJS = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

#$(LIBFT):
#	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(NAME) created and indexed"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	@rm -f $(OBJS)
#	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Object files deleted along with libft objs."

fclean: clean
	@rm -f $(NAME)
#	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re