# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 10:01:47 by rdiaz-fr          #+#    #+#              #
#    Updated: 2024/04/08 10:01:48 by rdiaz-fr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit

LIBRARIES = -Linc/MLX42/build -lmlx42 -L/Users/$(USER)/.brew/opt/glfw/lib -lglfw

SRC = src/main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(FRAMEWORKS) $(LIBRARIES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
