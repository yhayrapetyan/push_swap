SRC = 	my_helpers_NO-NORME.c \
		stack_operations3.c \
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

BONUS_SRC =	my_helpers_NO-NORME.c \
			get_next_line_utils.c \
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
# BONUS_OBJS = $(BONUS_SRC:.c=.o)
# BONUS_OBJS += $(OBJS)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)

$(OBJS): push_swap.h Makefile

sanitize:
	cc -fsanitize=address $(SRC) -o $(NAME)

bonus:
	$(CC) $(CFLAGS) $(BONUS_SRC) -o checker

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re sanitize
