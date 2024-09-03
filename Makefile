# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 15:18:00 by tbartocc          #+#    #+#              #
#    Updated: 2024/09/03 14:30:50 by tbartocc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = cc
FLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address
PRINTF = ./Printf/
LIBFT = ./Printf/Libft/

SRC_COMMON =	list_op/ft_lst_add_back.c \
				list_op/ft_lst_last.c \
				list_op/ft_lst_new.c \
				list_op/ft_lst_position.c \
				list_op/ft_lst_size.c \
				list_op/swap.c \
				list_op/rotate.c \
				list_op/push.c \
				list_op/reverse_rotate.c \
				get_next_line_utils.c \
				get_next_line.c \
				opti_rotate.c \
				rotate_lst.c \
				sort.c \
				sort_low.c \
				sort_big.c \
				utils.c \
				utils2.c \

SRC = $(SRC_COMMON)\
	push_swap.c	\

SRC_BONUS = $(SRC_COMMON)\
	checker.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) --no-print-directory -C $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) $(PRINTF)libftprintf.a -o $(NAME)

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)
	@$(MAKE) --no-print-directory -C $(PRINTF) clean
	@$(MAKE) --no-print-directory -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) --no-print-directory -C $(PRINTF) fclean
	@$(MAKE) --no-print-directory -C $(LIBFT) fclean

re: fclean all

bonus: $(OBJ_BONUS)
	@$(MAKE) --no-print-directory -C $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(PRINTF)libftprintf.a -o $(NAME_BONUS)

tester:
	@git clone https://github.com/SimonCROS/push_swap_tester

visualizer:
	@git clone https://github.com/o-reo/push_swap_visualizer.git
	@mkdir push_swap_visualizer/build
	@cd push_swap_visualizer/build && cmake ..
	@cd push_swap_visualizer/build && make

checker:
	@wget https://cdn.intra.42.fr/document/document/27319/checker_linux
	@chmod 777 checker_linux
	
end:
	@rm -rf checker_linux
	@rm -rf push_swap_tester
	@rm -rf push_swap_visualizer

.PHONY: all clean fclean re debug tester checker visualizer