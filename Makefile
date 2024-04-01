SRC = ./src/main.c

STACK_OPERATIONS_SRC =	reverse_rotate_operations.c \
						rotate_operations.c \
						push_operations.c \
						swap_operations.c


VALIDATION_SRC = 	check_for_empty_string.c \
					check_for_dublicates.c \
					is_valid_command.c \
					is_valid_input.c \
					ft_check_atoi.c \
					cut_new_line.c \
					fill_stack.c \
					ft_error.c

STACK_UTILS_SRC =	get_first_node.c \
					get_last_node.c \
					clean_stack.c \
					create_node.c \
					is_sorted.c \
					stack_len.c \
					add_node.c

HELPERS_SRC = 	print_2stacks_len.c \
				ft_print_stack.c \
				print_2stacks.c \
				free_split.c \
				ft_strchr.c \
				ft_strcmp.c \
				ft_strlen.c \
				ft_split.c \
				ft_log2.c \
				ft_sqrt.c

SORT_SRC = 		selection_sort.c \
				push_swap.c \
				sort_for3.c \
				sort_for5.c \
				sort.c

LIST_SRC =		execute.c \
				rotate.c \
				push.c \
				swap.c

GNL_SRC = 	get_next_line_utils.c \
			get_next_line.c 

BONUS_SRC = ./src/checker.c

HEADERS = push_swap.h

HEADERS_DIR = ./includes/
HELPERS_DIR = ./src/helpers/
CHECKER_DIR = ./checkers/
GNL_DIR = ./src/get_next_line/
LIST_DIR = ./src/list_operations/
VALIDATION_DIR = ./src/validation/
SORT_DIR = ./src/sorting_algorithms/
STACK_UTILS_DIR = ./src/stack/stack_utils/
STACK_OPERATIONS_DIR = ./src/stack/stack_operations/

HEADERS := $(addprefix $(HEADERS_DIR), $(HEADERS))
VALIDATION_SRC := $(addprefix $(VALIDATION_DIR), $(VALIDATION_SRC))
HELPERS_SRC := $(addprefix $(HELPERS_DIR), $(HELPERS_SRC))
GNL_SRC := $(addprefix $(GNL_DIR), $(GNL_SRC))
LIST_SRC := $(addprefix $(LIST_DIR), $(LIST_SRC))
SORT_SRC := $(addprefix $(SORT_DIR), $(SORT_SRC))
STACK_UTILS_SRC := $(addprefix $(STACK_UTILS_DIR), $(STACK_UTILS_SRC))
STACK_OPERATIONS_SRC := $(addprefix $(STACK_OPERATIONS_DIR), $(STACK_OPERATIONS_SRC)) 

SRC += $(HELPERS_SRC)
SRC += $(VALIDATION_SRC)
SRC += $(GNL_SRC)
SRC += $(LIST_SRC)
SRC += $(SORT_SRC)
SRC += $(STACK_UTILS_SRC)
SRC += $(STACK_OPERATIONS_SRC)

BONUS_SRC += $(HELPERS_SRC)
BONUS_SRC += $(VALIDATION_SRC)
BONUS_SRC += $(GNL_SRC)
BONUS_SRC += $(LIST_SRC)
BONUS_SRC += $(SORT_SRC)
BONUS_SRC += $(STACK_UTILS_SRC)
BONUS_SRC += $(STACK_OPERATIONS_SRC)

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)


UNAME = $(shell uname -s)
ifeq ($(UNAME),Darwin)
	CHECKER = checker_Mac
else
	CHECKER = checker_linux
endif
CHECKER := $(addprefix $(CHECKER_DIR), $(CHECKER)) 
SRC := $(shell printf "$(SRC)" | tr '\r' '\n')
SRC_COUNT_TOT := $(words $(SRC))
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS_NAME = checker
RM = rm -f
COUNT = 5

BLUE   = \033[0;34m
GREEN    = \033[0;32m
RED = \033[0;31m
YELLOW  = \033[0;33m
NO_COLOR    = \033[m

all: print_info $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@printf "%b" "$(BLUE)\n$@ $(GREEN)[✓]\n"

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) -o $(BONUS_NAME)
	@printf "%b" "$(BLUE)\n$@ $(GREEN)[✓]\n"

$(OBJS): $(HEADERS) Makefile
$(BONUS_OBJS): $(HEADERS) Makefile

sanitize:
	cc -fsanitize=address $(SRC) -o $(NAME)

sanitize_bonus:
	cc -fsanitize=address $(BONUS_SRC) -o $(BONUS_NAME)


bonus: print_info $(BONUS_OBJS) $(BONUS_NAME)

.c.o:
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@printf "\r%18s\r$(YELLOW)[ %d/%d (%d%%) ]$(NO_COLOR)" "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) -I $(HEADERS_DIR) -c $< -o $(<:.c=.o)

clean: print_name
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@printf "%b" "$(BLUE)$@: $(GREEN)[✓]\n"

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@printf "%b" "$(BLUE)$@: $(GREEN)[✓]\n"

re: fclean all
	@printf "%b" "$(BLUE)$@: $(GREEN)[✓]\n"

print_info: print_name
	@printf "%b" "$(BLUE)Compiler: $(GREEN)$(CC)\n"
	@printf "%b" "$(BLUE)Name: $(GREEN)$(NAME)\n"
	@printf "%b" "$(BLUE)Uname: $(GREEN)$(UNAME)\n"
	@printf "%b" "$(BLUE)C Flags: $(GREEN)$(CFLAGS)\n"
	@printf "%b" "$(BLUE)Src Count: $(GREEN)$(SRC_COUNT_TOT)\n"

print_name:
	@printf "%b" "$(BLUE)"
	@echo "     ____                    __          ____                                     "
	@echo "    /\  _\`\\                 /\ \        /\  _\`\                                   "
	@echo "    \ \ \L\ \ __  __    ____\ \ \___    \ \,\L\_\    __  __  __     __      ____   "
	@echo "     \ \ ,__//\ \/\ \  /',__\\ \  _ \`\\    \\/_\\__  \  /\ \/\ \/\ \  /'__ \`\  /\'_\`\\ "
	@echo "      \ \ \/ \ \ \_\ \/\__, \`\\ \ \ \ \     /\ \L\ \\ \ \_/ \_/ \ \/\L\. \_\\ \ \L\ \ "
	@echo "       \ \_\  \ \____/\/\____/\ \_\ \_\    \ \`____/\\ \___x___  /'\\__/.\_\ \ \ ,__/ "
	@echo "        \/_/   \/___/  \/___/  \/_/\/_/     \/_____/  \/__//__/  \/__/\/_/ \ \ \/  "
	@echo "                                                                            \ \_\   "
	@echo "                                                                             \/_/   "
	@printf "\n" 

test_checker: $(NAME) $(BONUS_NAME)
	$(eval ARG = $(shell jot -r $(COUNT) -5000000 5000000))
	@./push_swap $(ARG) | ./checker $(ARG)
	@echo  "Instructions "
	@./push_swap $(ARG) | wc -l

test_push_swap: $(NAME) $(BONUS_NAME)
	$(eval ARG = $(shell jot -r $(COUNT) -5000000 5000000))
	@./push_swap $(ARG) | $(CHECKER) $(ARG)
	@echo  "Instructions "
	@./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re sanitize bonus sanitize_bonus print_info print_name test_checker test_push_swap
