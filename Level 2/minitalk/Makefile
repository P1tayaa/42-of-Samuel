
SERVER_SRCS			= server.c

CLIENT_SRCS			= client.c

OBJS			= $(SRCS:%.c=%.o)

CC				= gcc

# CFLAGS			= -Wall -Werror -Wextra -I. -fsanitize=address
CFLAGS			= -Wall -Werror -Wextra -I.

SERVER			= server

CLIENT			= client

all:			$(SERVER) $(CLIENT)

$(SERVER):	server.c
				make -C ./mega_libft
				$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_SRCS) ./mega_libft/libft.a
				@echo   :white_check_mark:Done!
$(CLIENT):	client.c
				make -C ./mega_libft
				$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_SRCS) ./mega_libft/libft.a
				@echo   :white_check_mark:Done!

clean:
				@rm -f $(SERVER) $(CLIENT) && make clean -C ./mega_libft

fclean:			clean
				@rm -f -f $(SERVER) $(CLIENT) && make fclean -C ./mega_libft

re:				fclean all

.PHONY:			all clean fclean re
