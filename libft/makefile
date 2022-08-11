all:
	gcc -Wextra -Werror -Wall -c ./done/ft_strlen.c
	ar rc libft.a ./ft_strlen.o
clean:
	rm ./ft_strlen.o
fclean: clean
	rm libft.a
TestPC:
	gcc ./done/*.c
re: fclean all
libft.a: all