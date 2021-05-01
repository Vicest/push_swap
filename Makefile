# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 23:35:47 by vicmarti          #+#    #+#              #
#    Updated: 2021/05/01 20:19:15 by vicmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH := sources/common:sources/checker:sources/push_swap:sources/algorithms

CMN_FILES :=
CMN_FILES += load_stack.c
CMN_FILES += exit_handler.c

CHK_FILES :=
CHK_FILES += check_opts.c
CHK_FILES += print_sts.c
CHK_FILES += check_ordered.c
CHK_FILES += gnl.c
CHK_FILES += exit_handler.c
CHK_FILES += rotate.c
CHK_FILES += swap.c
CHK_FILES += push.c
CHK_FILES += checker.c

PSH_FILES :=
PSH_FILES += push_swap.c

SRC_DIR := sources
OBJ_DIR := objects

CMN_SRC :=  $(addprefix $(SRC_DIR)/common, $(CHK_FILES))
CHK_SRC :=  $(addprefix $(SRC_DIR)/checker, $(CHK_FILES))
ALG_SRC :=  $(addprefix $(SRC_DIR)/algorithms, $(PSH_FILES))
PHS_SRC :=  $(addprefix $(SRC_DIR)/push_swap, $(PSH_FILES))

CMN_OBJ := $(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(CMN_FILES)))
CHK_OBJ := $(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(CHK_FILES)))
PSH_OBJ := $(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(PSH_FILES)))

SRC_BNS_FILES :=
OBJ_BNS_FILES := $(patsubst %.c, %.o, $(SRC_BNS_FILES))

LIBFT :=
LIBFT += -Ilibft -Llibft -lft

SRC_BNS :=	$(addprefix $(SRC_DIR)/, $(SRC_BNS_FILES))
OBJ_BNS :=	$(addprefix $(OBJ_DIR)/, $(OBJ_BNS_FILES))

CC := gcc
CFLAGS := -Wall -Werror -Wextra -I. -g

.PHONY: all re clean fclean game norm
all : checker push_swap

checker : $(CMN_OBJ) $(CHK_OBJ) libft/libft.a
	@tput setaf 2
	@echo "Checker:"
	@tput sgr0
	$(CC) $(CFLAGS) $(LIBFT) $^ -o $@

push_swap : $(CMN_OBJ) $(PSH_OBJ) libft/libft.a
	@tput setaf 2
	@echo "Push_Swap:"
	@tput sgr0
	$(CC) $(CFLAGS) $(LIBFT) $^ -o $@

$(NAME) : checker push_swap

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

fclean : clean

re : fclean all
