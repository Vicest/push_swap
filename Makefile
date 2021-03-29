# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 23:35:47 by vicmarti          #+#    #+#              #
#    Updated: 2021/03/29 14:31:33 by vicmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHK_FILES :=
CHK_FILES += print_sts.c
CHK_FILES += gnl.c
CHK_FILES += exit_handler.c
CHK_FILES += swap.c
CHK_FILES += push.c
CHK_FILES += checker.c

PSH_FILES :=
PSH_FILES += push_swap.c

SRC_DIR := sources/
OBJ_DIR := objects/

CHK_SRC :=  $(addprefix $(SRC_DIR), $(CHK_FILES))

CHK_OBJ := $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(CHK_FILES)))
PSH_OBJ := $(patsubst %.c, %.o, $(PSH_FILES))

SRC_BNS_FILES :=
OBJ_BNS_FILES := $(patsubst %.c, %.o, $(SRC_BNS_FILES))

LIBFT :=
LIBFT += -Ilibft -Llibft -lft

SRC_BNS :=	$(addprefix $(SRC_DIR), $(SRC_BNS_FILES))
OBJ_BNS :=	$(addprefix $(OBJ_DIR), $(OBJ_BNS_FILES))

NAME := game

CC := gcc
CFLAGS := -Wall -Werror -Wextra -I. -g

.PHONY: all re clean fclean game
all : $(NAME)

checker : $(CHK_OBJ) libft/libft.a
	$(CC) $(CFLAGS) $(LIBFT) $^ -o $@

push_swap : libft/libft.a

$(NAME) : checker push_swap

$(OBJ_DIR)%.o :$(SRC_DIR)%.c
	@echo "Building object."
	@mkdir -vp $(OBJ_DIR)
	$(CC) $(CFLAGS) $<  -c -o $@
	@echo "______________________________"

clean :
	@echo "Cleaning."
	@rm -rv $(OBJ) checker push_swap
	@echo "______________________________"

fclean :
	@echo "Forced cleaning."
	@rm -rfv $(OBJ_DIR) checker push_swap
	@echo "______________________________"

re : fclean all
