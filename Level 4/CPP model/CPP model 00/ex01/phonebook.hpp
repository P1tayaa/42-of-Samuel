/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:09:42 by sboulain          #+#    #+#             */
/*   Updated: 2023/08/17 12:09:42 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

class contact
{
	public:
	
	contact();
	contact(std::string first_name, std::string last_name,
			std::string nickname, std::string phone_number,
			std::string darkest_secret);
	~contact();
	std::string	get_first_name();
	std::string	get_last_name();
	std::string	get_nickname();
	void		print_contact_detail();

	private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};

class phonebook
{
	public:
		phonebook(void);
		~phonebook(void);

		int	add_contact(void);
		int	search_contact(void);
		int	exit_prgram(void);
	
	private:
	static const int	max_contontac = 8;
	contact		contacts[max_contontac];
	int			current_index;
	
};
