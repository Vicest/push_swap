VPATH := sources/common:sources/pushswap

MAKEFILES += " -j $(shell sysctl -n hw.ncpu)"

NAME := push_swap

CMN_FILES :=
CMN_FILES += do_instr.c
CMN_FILES += do_sequence.c
CMN_FILES += log_and_do.c
CMN_FILES += log_and_do_n.c
CMN_FILES += log_and_do_sequence.c
CMN_FILES += load_stack.c
CMN_FILES += preprocess_stack.c
CMN_FILES += exit_handler.c
CMN_FILES += arr_sort.c
CMN_FILES += is_sorted.c
CMN_FILES += index_of.c
CMN_FILES += print_status.c
CMN_FILES += get_position.c
CMN_FILES += stack_size.c
CMN_FILES += peek.c
CMN_FILES += rotate.c
CMN_FILES += swap.c
CMN_FILES += push.c

PSH_FILES :=
PSH_FILES += reset.c
PSH_FILES += quick.c
PSH_FILES += sort_3_and_rotate.c
PSH_FILES += optimizations.c
PSH_FILES += brute.c
PSH_FILES += insertion_sort.c
PSH_FILES += copy_instructions.c
PSH_FILES += push_swap.c

INC_DIR := includes
OBJ_DIR := objects

CMN_OBJ := $(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(CMN_FILES)))
PSH_OBJ := $(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(PSH_FILES)))

SRC_BNS_FILES :=
OBJ_BNS_FILES := $(patsubst %.c, %.o, $(SRC_BNS_FILES))

LIBFT := libft/libft.a

CC := gcc
CFLAGS := -Wall -Werror -Wextra -I$(INC_DIR) -g #-fsanitize=address
LN_FLAGS := -Llibft -lft

.PHONY: all re clean fclean norm
all : $(NAME)

$(NAME) : $(CMN_OBJ) $(PSH_OBJ) $(LIBFT)
	@tput setaf 2
	@echo "Push_Swap:"
	@tput setaf 8
	$(CC) $(CFLAGS) $(LN_FLAGS) $^ -o $@
	@tput sgr0

$(LIBFT) :
	@make -C libft
	@ln -vfs libft/libft.h $(INC_DIR)/

$(OBJ_DIR)/%.o :%.c
	@mkdir -vp $(OBJ_DIR)
	@tput setaf 8
	$(CC) $(CFLAGS) $<  -c -o $@
	@tput sgr0

norm :
	@norminette $(CHK_SRC)

clean :
	@echo "Cleaning:"
	@tput setaf 3
	@rm -rfv $(OBJ_DIR) push_swap
	@tput sgr0

libclean :
	@make -C libft fclean
	@unlink $(INC_DIR)/libft.h

fclean : clean

re :
	@make fclean
	@make all
