INCLUDES = -I/opt/X11/include -Imlx

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)
