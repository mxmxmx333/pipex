# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 10:57:59 by mbonengl          #+#    #+#              #
#    Updated: 2024/08/09 11:36:42 by mbonengl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name 		:= 	pipex
CFLAGS 		:= 	-g -I./inc -I./libft/inc -Wall -Wextra -Werror
BFLAGS		:= 	-g -I./bonus/inc
LDFLAGS		:= 	-L./libft -lft
CC 			:= 	cc
SRC_DIR 	:= 	./src
OBJ_DIR 	:= 	./obj
INC_DIR 	:= 	./inc
BONUS_DIR	:= 	./bonus
B_INC_DIR	:= 	./bonus/inc
B_SRC_DIR	:= 	./bonus/src
B_OBJ_DIR	:= 	./bonus/obj
LIBFT_DIR	:= 	./libft
LIBFT		:= 	$(LIBFT_DIR)/libft.a
SRC 		:=	$(SRC_DIR)/main.c \
				$(SRC_DIR)/errors.c \
				$(SRC_DIR)/init.c \
				$(SRC_DIR)/deallocate.c \
				$(SRC_DIR)/testing.c \
				$(SRC_DIR)/check_files.c \
				$(SRC_DIR)/exec_cmds.c
BSRC		:=	$(B_SRC_DIR)/main_bonus.c \
				$(B_SRC_DIR)/errors_bonus.c \
				$(B_SRC_DIR)/init_bonus.c \
				$(B_SRC_DIR)/deallocate_bonus.c \
				$(B_SRC_DIR)/testing_bonus.c \
				$(B_SRC_DIR)/check_files_bonus.c \
				$(B_SRC_DIR)/exec_cmds_bonus.c
OBJ 		:= 	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BOBJ		:=	$(BSRC:$(B_SRC_DIR)/%.c=$(B_OBJ_DIR)/%.o)

all: $(Name)

$(Name): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(Name) $(OBJ) $(LDFLAGS)

bonus: $(BOBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BFLAGS) -o $(Name) $(BOBJ) $(LDFLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(B_OBJ_DIR)/%.o: $(B_SRC_DIR)/%.c | $(B_OBJ_DIR)
	$(CC) $(CFLAGS) $(BFLAGS) -c $< -o $@

$(B_OBJ_DIR):
	mkdir -p $(B_OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ) $(BOBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(Name)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
