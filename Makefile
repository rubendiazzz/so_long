# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 10:44:09 by rdiaz-fr          #+#    #+#              #
#    Updated: 2024/04/18 12:45:07 by rdiaz-fr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long
CFLAGS = -Wall -Wextra -Werror
LIBMLX  = ./inc/MLX42
LIBFT   = ./inc/libft

HEADERS = -I ./inc -I ${LIBMLX}/include -I ${LIBFT}
LIBGL   = -lglfw -L"/Users/$(USER)/.brew/Cellar/glfw/3.4/lib"
LIBS    = ${LIBGL} ${LIBFT}/libft.a ${LIBMLX}/build/libmlx42.a
SRCS    = ./src/main.c
OBJS    = ${SRCS:.c=.o}

all: libmlx libft ${NAME}

libft:
	@echo "Compiling libft..."
	@${MAKE} -s -C ${LIBFT}
	@echo "libft compilation complete."

libmlx:
	@echo "Compiling MLX42..."
	@rm -rf $(LIBMLX)/build
	@cd $(LIBMLX) && mkdir -p build && cd build && cmake .. > /dev/null && make -s -j4 > /dev/null
	@echo "MLX42 compilation complete."

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

${NAME}: ${OBJS}
	@echo "Linking $@..."
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$@ compilation complete."

clean:
	@echo "Cleaning up object files..."
	@rm -f ${OBJS}
	@${MAKE} -s -C ${LIBFT} clean
	@${MAKE} -s -C ${LIBMLX}/build clean
	@echo "Cleanup complete."

fclean: clean
	@echo "Cleaning up executable and libraries..."
	@rm -f ${NAME}
	@${MAKE} -s -C ${LIBFT} fclean
	@echo "Cleanup complete."

re: fclean all

.PHONY: all clean fclean re libmlx libft
