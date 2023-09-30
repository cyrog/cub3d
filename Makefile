# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 14:23:07 by lobertho          #+#    #+#              #
#    Updated: 2023/09/30 14:07:07 by cgross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS = $(wildcard *.c)	\
	   $(wildcard gnl/*.c)	\
	   $(wildcard parsing/*.c)	\
	   $(wildcard parsing/utils/*.c)	\
	  # $(wildcard parsing/map/*.c)	\

OBJS = $(SRCS:.c=.o)

CC = gcc -Wall -Wextra -Werror

FLAGS = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) -I./mlx -Lmlx -lmlx $(FLAGS) -o $(NAME) $(OBJS)
	
clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)
cleanswap: clean
		rm -f ./.*.sw*
		rm -f ./parsing/.*.sw*
		rm -f ./parsing/map/.*.sw*
		rm -f ./parsing/utils/.*.sw*

re: fclean all
