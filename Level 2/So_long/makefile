
SRCS			= so_long.c map_valid_string.c map_making.c map_making_p2.c flud_fill_check.c load_map.c load_cells.c player_moves.c path_png_stuff.c find_coordinate_need_to_access.c check_map_tools.c

OBJS			= $(SRCS:%.c=%.o)

DEBUGGING	?=

ifdef DEBUG
	DEBUGGING += -fsanitize=address -g
endif

CC				= gcc

# CFLAGS			= -Wall -Werror -Wextra -I. -fsanitize=address
CFLAGS			= -Wall -Werror -Wextra

NAME			= so_long

all:			$(NAME)

$(NAME): $(OBJS)
				make -C ./mega_libft
				make -C ./MLX42/build
# $(CC) $(CFLAGS) -o $(NAME) $(SRCS) ./mega_libft/libft.a ./MLX42/build/libmlx42.a -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw3
				$(CC) $(CFLAGS) $(DEBUGGING) -o $(NAME) $(SRCS) ./mega_libft/libft.a ./MLX42/build/libmlx42.a -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
# $(CC) $(CFLAGS) ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -I ./include -I ./MLX42/build/libmlx42.a/include -o $(NAME) $(SRCS) ./mega_libft/libft.a
				@echo   :white_check_mark:Done!



# clean:
# 				@rm -f $(OBJS)

# fclean:			clean
# 				@rm -f $(NAME)



# right one just for faster load I will use above

clean:
				@rm -f $(OBJS) && make clean -C ./mega_libft && make -C ./mega_libft clean
fclean:			clean
				@rm -f $(NAME) && make fclean -C ./mega_libft

re:				fclean $(NAME)

.PHONY:			all clean fclean re
