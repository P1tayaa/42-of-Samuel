/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:14:49 by sboulain          #+#    #+#             */
/*   Updated: 2024/02/02 11:49:47 by sboulain         ###   ########.fr       */
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

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else 
	{
		for (int i = 0; i < argc; i++)
		{
			print_in_capital(argv[i]);
		}
	}
	return (0);
}
