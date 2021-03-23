# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 23:35:47 by vicmarti          #+#    #+#              #
#    Updated: 2021/03/21 20:33:29 by vicmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHK_FILES :=
CHK_FILES += checker.c

PSH_FILES :=
PSH_FILES += push_swap.c

OBJ_FILES := $(patsubst %.s, %.o, $(CHK_FILES))
OBJ_FILES += $(patsubst %.s, %.o, $(PSH_FILES))

SRC_BNS_FILES :=
OBJ_BNS_FILES := $(patsubst %.s, %.o, $(SRC_BNS_FILES))

LIBS :=
LIBS += ft.a

SRC_DIR := sources/
OBJ_DIR := objects/

SRC :=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ :=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
INC :=	includes

SRC_BNS :=	$(addprefix $(SRC_DIR), $(SRC_BNS_FILES))
OBJ_BNS :=	$(addprefix $(OBJ_DIR), $(OBJ_BNS_FILES))

NAME := game

CC := cc
CFLAGS := -Wall -Werror -Wextra -I$(INC) -L. -l$(LIBS)

.PHONY: all re clean fclean game
all : $(NAME)

checker : $(patsubst %.s, %.o, $(CHK_FILES)) libft.a

push_swap : libft.a

$(NAME) : checker push_swap
	@echo "Building everything."
	@echo "______________________________"

$(OBJ_DIR)%.o : $(SRC_DIR)%.s
	@echo "Building object."
	@mkdir -vp $(OBJ_DIR)
	$(CC) 
	$(AS) $(ASFLAGS) $? -o $@
	@echo "______________________________"

clean :
	@echo "Cleaning."
	@rm -rv $(OBJ) $(NAME)
	@echo "______________________________"

fclean :
	@echo "Forced cleaning."
	@rm -rfv $(OBJ) $(NAME)
	@echo "______________________________"

re : fclean all
