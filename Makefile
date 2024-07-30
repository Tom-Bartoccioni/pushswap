# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 14:34:27 by tbartocc          #+#    #+#              #
#    Updated: 2024/07/14 15:17:37 by tbartocc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
PRINTF = ./Printf/

SRC =	push_swap.c	\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(PRINTF)
	cp $(PRINTF)libftprintf.a $(NAME)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(PRINTF) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re
