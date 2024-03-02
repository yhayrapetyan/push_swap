SRC = 	ft_split.c \
		stack_operations.c \
		my_helpers_NO-NORME.c \
		push_swap.c \
		helpers.c \
		stack_utils.c \
		validation.c \
		sort_for5.c \
		sort_for3.c \
		sort.c \
		main.c \
		selection_sort.c

OBJS = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)

$(OBJS): push_swap.h Makefile

sanitize:
	cc -fsanitize=address $(SRC) -o $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re sanitize
