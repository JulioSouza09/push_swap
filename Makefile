# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/18 18:06:00 by jcesar-s          #+#    #+#              #
#    Updated: 2025/08/30 20:10:52 by jcesar-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
IDIR = includes/
LFTDIR = $(IDIR)libft/
LFT = $(LFTDIR)libft.a
CDIR = src/
ODIR = objs/
_SRC = main.c stack_creator.c stack_utils.c parser_utils.c utils.c
_SRC += sorting_utils.c initializer.c swap.c push.c rotate.c reverse_rotate.c
_SRC += calc_moves.c sorting_algorithms.c sort_bigger_utils.c get_targets.c
_SRC += find_cheapest.c
SRC = $(patsubst %, $(CDIR)%, $(_SRC))
OBJS = $(patsubst %.c, $(ODIR)%.o, $(_SRC))
_DEPS = push_swap.h
DEPS = $(patsubst %, $(IDIR)%, $(_DEPS))

.PHONY: all clean fclean re

$(ODIR)%.o: $(CDIR)%.c $(DEPS)
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -I $(IDIR) -I $(LFTDIR) -c $< -o $@ 

all: $(NAME)

debug:
	@echo "$(SRC)"
	@echo "$(OBJS)"
	@echo "$(DEPS)"

$(NAME): $(OBJS) $(LFT)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -L $(LFTDIR) -lft

$(LFT):
	make -C $(LFTDIR)

clean:
	make clean -C $(LFTDIR)
	rm -rf $(ODIR)

fclean: clean
	make fclean -C $(LFTDIR)
	rm -f $(NAME)

re: fclean all
