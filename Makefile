CC = cc

PATH_F = func
C_FILES_FUNC = $(PATH_F)/free.c $(PATH_F)/ft_atoi.c $(PATH_F)/check_and_add_args.c \
$(PATH_F)/ft_split.c $(PATH_F)/list.c $(PATH_F)/info.c $(PATH_F)/my_print.c

PATH_I = instructions
C_FILES_INST = $(PATH_I)/push.c $(PATH_I)/reverse.c $(PATH_I)/rotate.c \
$(PATH_I)/swap.c

PATH_A = algorithm
C_FILES_ALGO = $(PATH_A)/check_list.c $(PATH_A)/small_sort.c $(PATH_A)/middle_sort.c

PATH_B = bonus
C_FILES_BONUS = $(PATH_B)/checker_bonus.c $(PATH_B)/read_bonus.c $(PATH_F)/ft_split.c \
$(PATH_B)/push_bonus.c $(PATH_B)/reverse_bonus.c $(PATH_B)/rotate_bonus.c $(PATH_B)/swap_bonus.c \
$(PATH_B)/check_validity.c $(C_FILES)

C_FILES = $(C_FILES_FUNC) $(C_FILES_INST) $(C_FILES_ALGO) push_swap.c
O_FILES = $(C_FILES:.c=.o)
BONUS_O_FILES = $(C_FILES_BONUS:.c=.o)
FLAGS = -Wall -Wextra -Werror
NAME = push_swap.a
BONUS_NAME = checker.a
EXE = push_swap
BONUS_EXE = checker

all:$(NAME)

bonus:$(BONUS_NAME)

$(NAME):$(O_FILES)
	ar -rcs $(NAME) $(O_FILES)
	$(CC) $(NAME) -o $(EXE)

$(BONUS_NAME):$(BONUS_O_FILES)
	ar -rcs $(BONUS_NAME) $(BONUS_O_FILES)
	$(CC) $(BONUS_NAME) -o $(BONUS_EXE)

%.o:%.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(O_FILES) $(BONUS_O_FILES)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re