SRC =	stack_operations3.c \
		my_helpers_NO-NORME.c \
		stack_operations2.c \
		stack_operations.c \
		list_operations.c \
		selection_sort.c \
		stack_utils2.c \
		stack_utils.c \
		validation.c \
		validation2.c \
		push_swap.c \
		sort_for3.c \
		sort_for5.c \
		ft_split.c \
		helpers2.c \
		helpers.c \
		main.c \
		sort.c

BONUS_SRC = get_next_line_utils.c \
			my_helpers_NO-NORME.c \
			validation_checker.c \
			stack_operations3.c \
			stack_operations2.c \
			stack_operations.c \
			list_operations.c \
			selection_sort.c \
			get_next_line.c \
			stack_utils2.c \
			stack_utils.c \
			validation2.c \
			validation.c \
			push_swap.c \
			sort_for3.c \
			sort_for5.c \
			ft_split.c \
			helpers2.c \
			helpers.c \
			checker.c \
			sort.c \

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS_NAME = checker
RM = rm -f

# paased project without satinize targets and my_helpers functions

all: $(NAME)

$(NAME): $(OBJS)

$(OBJS): push_swap.h Makefile
$(BONUS_OBJS): push_swap.h Makefile

sanitize:
	cc -fsanitize=address $(SRC) -o $(NAME)

sanitize_bonus:
	cc -fsanitize=address $(BONUS_SRC) -o $(BONUS_NAME)


bonus: $(BONUS_OBJS) $(BONUS_NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

.PHONY: all clean fclean re sanitize bonus
