all:
	gcc -Wextra -Werror -Wall -I -c ./done/*.c
	ar rc libft.a ./*.o
clean:
	rm ./*.o
fclean: clean
	rm libft.a
TestPC:
	gcc ./done/*.c
	./a.out
re: fclean all
libft.a: all