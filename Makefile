# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 14:34:27 by tbartocc          #+#    #+#              #
#    Updated: 2024/08/26 16:04:20 by tbartocc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
PRINTF = ./Printf/

SRC =	list_op/ft_lst_add_back.c \
		list_op/ft_lst_last.c \
		list_op/ft_lst_new_index.c \
		list_op/ft_lst_position.c \
		list_op/ft_lst_size.c \
		list_op/swap.c \
		list_op/rotate.c \
		list_op/push.c \
		list_op/reverse_rotate.c \
		push_swap.c	\
		sort.c \
		sort_big.c \
		utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(PRINTF)
	$(CC) $(CFLAGS) -fsanitize=address $(OBJ) $(PRINTF)libftprintf.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -fsanitize=address -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(PRINTF) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF) fclean

re: fclean all

tkt:
	rm -f $(OBJ) $(NAME)
	$(MAKE) all

.PHONY: all clean fclean re
