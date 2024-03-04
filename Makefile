NAME    = so_long
CFLAGS = -Wall -Wextra -Werror
LIBMLX  = ./inc/mlx
LIBFT   = ./libft

HEADERS = -I ./includes -I ${LIBMLX}/include -I ${LIBFT}
LIBGL   = -lglfw -L"/Users/rdiaz-fr/.brew/opt/glfw/lib"
LIBS    = ${LIBGL} ${LIBFT}/libft.a ${LIBMLX}/build/libmlx42.a
SRCS    = main.c key_hooks.c error_handling.c close.c
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