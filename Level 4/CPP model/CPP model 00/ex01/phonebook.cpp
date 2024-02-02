/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:09:12 by sboulain          #+#    #+#             */
/*   Updated: 2024/02/02 12:27:23 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

contact::contact(std::string first_name, std::string last_name,
				 std::string nickname, std::string phone_number,
				 std::string darkest_secret)
	: first_name(first_name), last_name(last_name),
	  nickname(nickname), phone_number(phone_number),
	  darkest_secret(darkest_secret) {
		std::cout << "Contact successfully made\n";
}

contact::contact()
{
	this->first_name = "tom";
	this->last_name = "Jerry";
	this->nickname = "Mouse and Piket";
	this->phone_number = "2";
	this->darkest_secret = "they are friends";
}


contact::~contact() 
{
	std::cout << "Contact successfully removed\n";
}

std::string	contact::get_first_name()
{
	return (this->first_name);
}

std::string	contact::get_last_name()
{
	return (this->last_name);
}

std::string	contact::get_nickname()
{
	return (this->nickname);
}

void	contact::print_contact_detail()
{
	std::cout << std::endl << "first name: " << this->first_name << std::endl;
	std::cout << "last name: " << this->last_name << std::endl;
	std::cout << "nickname: " << this->nickname << std::endl;
	std::cout << "phone number: " << this->phone_number << std::endl;
	std::cout << "darkest_secret: " << this->darkest_secret << std::endl  << std::endl ;
}


phonebook::phonebook() 
{
	this->current_index = 0;
	for (int i = 0; i <= this->max_contontac; i++)
	{
		this->contacts[i] = NULL;
	}
}


phonebook::~phonebook() 
{
	int	i = 0;
	while (this->contacts[i] != NULL)
	{
		delete this->contacts[i];
		i++;
	}
	std::cout << "phonebook power off\n";
}


int phonebook::add_contact() 
{
	std::string	user_input[5];

	if (this->current_index == 8)
		this->current_index = 0;
	if (this->contacts[this->current_index] != NULL)
	{
		delete this->contacts[this->current_index];
		this->contacts[this->current_index] = NULL;
	}
	std::cout << "What is their first name of said contact\n";
	std::cin >> user_input[0];
	std::cout << "What is their last name of said contact\n";
	std::cin >> user_input[1];
	std::cout << "What is their nickname of said contact\n";
	std::cin >> user_input[2];
	std::cout << "What is their phone_number of said contact\n";
	std::cin >> user_input[3];
	std::cout << "What is their darkest_secret of said contact\n";
	std::cin >> user_input[4];
	this->contacts[this->current_index] = new contact(user_input[0], user_input[1], user_input[2], user_input[3], user_input[4]);
	this->current_index++;
	return 0;
}

std::string	format_sting_with_dots(std::string input, int trun_size)
{
	if (input.length() == (unsigned long)trun_size)
		return (input);
	if (input.length() < (unsigned long)trun_size)
		return (input + std::string(trun_size - input.length(), '.'));
	// if (input.length() > trun_size)
	return (input.substr(0, trun_size));
}

int	is_valid_index(std::string	user_input)
{
	// Use a stringstream to convert the input to an integer
	std::istringstream	iss(user_input);
	int	index;

 	// Try to extract an integer from the input
	if (iss >> index)
		return (index);
	return (-1);
}

int phonebook::search_contact() 
{
	int i;

	if (this->contacts[0] == NULL)
	{
		std::cout << "No contact yet\n";
		return (1);
	}
	std::cout	<< std::setw(10) << "index" << "|"
				<< std::setw(10) << "first name" << "|"
				<< std::setw(10) << "last name" << "|"
				<< std::setw(10) << "nickname" << "|" << std::endl;
	i = 0;
	while (this->contacts[i] != NULL)
	{
		std::cout	<< std::setw(10) << i << "|"
					<< std::setw(10) << format_sting_with_dots(this->contacts[i]->get_first_name(), 10) << "|"
					<< std::setw(10) << format_sting_with_dots(this->contacts[i]->get_last_name(), 10) << "|"
					<< std::setw(10) << format_sting_with_dots(this->contacts[i]->get_nickname(), 10) << "|" << std::endl;
		i++;
	}
	

	std::string	user_input;
	int			index_wanted = -1;

	while (index_wanted == -1)
	{
		std::cout << "What contact do you want full info\n";
		std::cin >> user_input;
		index_wanted = is_valid_index(user_input);
		if (index_wanted >= this->max_contontac)
			index_wanted = -1;
		if (index_wanted != -1)
		{
			if (this->contacts[index_wanted] == NULL)
				index_wanted = -1;
		}
	}
	this->contacts[index_wanted]->print_contact_detail();
	return 0;
}


int phonebook::exit_prgram() 
{
	return 0; 
}

int main()
{
	std::string	user_input;
	phonebook	the_phonebook;

	while (user_input.compare("EXIT") != 0)
	{
		std::getline(std::cin, user_input);
		if (user_input.compare("ADD") == 0)
			the_phonebook.add_contact();
		else if (user_input.compare("SEARCH") == 0)
			the_phonebook.search_contact();
		else if (user_input.compare("EXIT") != 0 || user_input.length() == 0)
			std::cout << "\nNot valid input, try ADD, SEARCH or EXIT" << std::endl;
	}
	return (0);
}