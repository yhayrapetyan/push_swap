SRC = 	my_helpers_NO-NORME.c \
		stack_operations3.c \
		stack_operations2.c \
		stack_operations.c \
		list_operations.c \
		selection_sort.c \
		stack_utils2.c \
		stack_utils.c \
		validation.c \
		push_swap.c \
		sort_for3.c \
		sort_for5.c \
		ft_split.c \
		helpers2.c \
		helpers.c \
		main.c \
		sort.c

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
