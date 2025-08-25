# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/18 18:06:00 by jcesar-s          #+#    #+#              #
#    Updated: 2025/08/25 15:42:42 by jcesar-s         ###   ########.fr        #
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
_SRC = main.c stack_creator.c stack_utils.c parser_utils.c utils.c single_ops.c
_SRC += multi_ops.c sorting_utils.c initializer.c
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
