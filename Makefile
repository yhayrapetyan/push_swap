SRC = 	ft_check_atoi.c \
		ft_split.c \
		helpers.c \
		main.c \
		my_helpers_NO-NORME.c \
		push_swap.c \
		stack_operations.c \
		stack_utils.c \
		validation.c

OBJS = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)

$(OBJS): push_swap.h Makefile

sanitize:
	cc -fsanitize=address *.c -o push_swap

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re sanitize
