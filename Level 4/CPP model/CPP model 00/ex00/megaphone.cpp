/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:14:49 by sboulain          #+#    #+#             */
/*   Updated: 2023/08/16 17:14:49 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	print_in_capital(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] >= 'a' && string[i] <= 'z')
			std::cout << (char) std::toupper(string[i]);
		else 
			std::cout << string[i];
		i++;
	}
	
}

void	print_in_capital_add_different_punct(char *string, char char_punct)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] >= 'a' && string[i] <= 'z')
			std::cout << (char) std::toupper(string[i]);
		else if (string[i] == '.')
			std::cout << (char) char_punct;
		else 
			std::cout << string[i];
		i++;
	}
	
}

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (argc == 2)
	{
		print_in_capital(argv[1]);
		std::cout << std::endl;
	}
	else if (argc == 4)
	{
		print_in_capital_add_different_punct(argv[3], argv[2][1]);
		std::cout << std::endl;
	}
	return (0);
}
