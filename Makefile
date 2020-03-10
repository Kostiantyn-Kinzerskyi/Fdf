# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/25 15:02:32 by kkinzers          #+#    #+#              #
#    Updated: 2019/03/13 15:49:56 by kkinzers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIB_H = -L ./lib
LIB_DIR = ./libft

SRC = fdf.c get_next_line.c read.c putp.c zoom.c rotate.c validator.c projection.c

SRCO = $(SRC:.c=.o)

HEADER = fdf.h
HEADER_FLAGS = -I $(HEADER)

FLAGS = -Wall -Wextra -Werror -O3
L_FLAGS = -lmlx -framework OpenGL -framework AppKit

LIB = $(LIB_DIR)libft.a
LIB_FLAGS = -lft -L $(LIB_DIR)

all: $(NAME)

$(LIB):
	@make -C $(LIB_DIR)
$(NAME): $(LIB) $(SRCO)
	@gcc $(SRCO) $(LIB_FLAGS) -o $(NAME) $(L_FLAGS)
%.o: %.c
	gcc -c $< -o $@ -I $(HEADER)
clean:
	@rm -f $(SRCO)
	@make clean -C $(LIB_DIR)
fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_DIR)
re: fclean all
