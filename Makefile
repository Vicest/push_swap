# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 23:35:47 by vicmarti          #+#    #+#              #
#    Updated: 2021/05/14 20:39:09 by vicmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH := sources/common:sources/push_swap:sources/algorithms

NAME := push_swap

CMN_FILES :=
CMN_FILES += load_stack.c
CMN_FILES += exit_handler.c
CMN_FILES += is_sorted.c
CMN_FILES += rotate.c
CMN_FILES += swap.c
CMN_FILES += push.c

#CHK_FILES :=
#CHK_FILES += check_opts.c
#CHK_FILES += print_sts.c
#HK_FILES += gnl.c
#CHK_FILES += exit_handler.c
#CHK_FILES += checker.c

PSH_FILES :=
PSH_FILES += bubble.c
PSH_FILES += try_ra.c
PSH_FILES += try_sa.c
PSH_FILES += backtrace.c
PSH_FILES += push_swap.c

SRC_DIR := sources
INC_DIR := includes
OBJ_DIR := objects

#CMN_SRC :=  $(addprefix $(SRC_DIR)/common, $(CHK_FILES))
#CHK_SRC :=  $(addprefix $(SRC_DIR)/checker, $(CHK_FILES))
#ALG_SRC :=  $(addprefix $(SRC_DIR)/algorithms, $(PSH_FILES))
#PHS_SRC :=  $(addprefix $(SRC_DIR)/push_swap, $(PSH_FILES))

CMN_OBJ := $(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(CMN_FILES)))
#CHK_OBJ := $(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(CHK_FILES)))
PSH_OBJ := $(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(PSH_FILES)))

SRC_BNS_FILES :=
OBJ_BNS_FILES := $(patsubst %.c, %.o, $(SRC_BNS_FILES))

LIBFT := libft/libft.a

SRC_BNS :=	$(addprefix $(SRC_DIR)/, $(SRC_BNS_FILES))
OBJ_BNS :=	$(addprefix $(OBJ_DIR)/, $(OBJ_BNS_FILES))

CC := gcc
CFLAGS := -Wall -Werror -Wextra -I$(INC_DIR) -g
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

#checker : $(CMN_OBJ) $(CHK_OBJ) $(LIBFT)
#	@tput setaf 2
#	@echo "Checker:"
#	@tput setaf 8
#	$(CC) $(CFLAGS) $(LN_FLAGS) $^ -o $@
#	@tput sgr0

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
	@rm -rfv $(OBJ_DIR) checker push_swap
	@tput sgr0

libclean :
	@make -C libft fclean
	@unlink $(INC_DIR)/libft.h

fclean : clean

re : fclean all
