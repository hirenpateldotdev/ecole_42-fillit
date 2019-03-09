# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/16 16:54:10 by hirenpat          #+#    #+#              #
#    Updated: 2019/02/17 01:17:12 by hirenpat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
SRCS = backtrack.c flags.c grid.c input.c libft.c libft_math.c main.c points.c tet.c free.c
OBJ = ${SRCS:.c=.o}

all: $(NAME)
$(NAME):
	@gcc $(FLAGS) -I. -c -g $(SRCS) 
	@gcc $(FLAGS) $(OBJ) -o $(NAME)
clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
