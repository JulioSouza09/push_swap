# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/18 18:06:00 by jcesar-s          #+#    #+#              #
#    Updated: 2025/08/18 18:44:07 by jcesar-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
IDIR = include/
CDIR = src/
ODIR = objs/
_SRC = main.c 
SRC = $(patsubst %, $(CDIR)%, $(_SRC))
OBJS = $(patsubst %.c, $(ODIR)%.o, $(_SRC))

.PHONY: all clean fclean re

$(ODIR)%.o: $(CDIR)%.c
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

debug:
	@echo "$(SRC)"
	@echo "$(OBJS)"

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
