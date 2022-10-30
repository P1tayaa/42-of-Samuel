
# SRCS			= main.c

# OBJS			= $(SRCS:%.c=%.o)

# CC				= gcc

# CFLAGS			= -Wall -Werror -Wextra -I.

# NAME			= fdf.a

# all:			$(NAME)

# $(NAME):
# 				make -C ./mlx
# 				cp ./mlx/libmlx.a ./fdf.a
# 				@echo   :white_check_mark:Done!
# clean:
# 				@rm -f $(OBJS) && make clean -C ./mlx

# fclean:			clean
# 				@rm -f $(NAME) && make clean -C ./mlx
# test:			all
# 				$(CC) $(CFLAGS) $(SRCS) fdf.a

# re:				fclean $(NAME)

# .PHONY:			all clean fclean re


NAME = fdf
LIBFT	= libft.a
MLX	= libmlx.a

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
DLIBS	= -framework OpenGL -framework AppKit

all	: $(NAME)

$(NAME)	: $(OBJ) $(LIBFT) $(MLX) src/main.c
	$(CC) $(CFLAGS) $^ $(DLIBS) -I$(INC) -o $@

obj/%.o	: */%.c
	@mkdir -p obj/
	$(CC) $(CFLAGS) -c -I$(INC) $< -o $@

$(LIBFT) :
	@make -C libft/
	@cp libft/$@ .

$(MLX)	:
	@make -C mlx/
	@cp mlx/$@ .