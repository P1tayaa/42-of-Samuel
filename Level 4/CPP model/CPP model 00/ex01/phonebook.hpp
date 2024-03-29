#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

class Contact
{
	public:
	
	Contact();
	void	make_contact(std::string first_name, std::string last_name,
			std::string nickname, std::string phone_number,
			std::string darkest_secret);
	~Contact();
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

class Phonebook
{
	public:
		Phonebook(void);
		~Phonebook(void);

		int	add_contact(void);
		int	search_contact(void);
		int	exit_prgram(void);
	
	private:
	static const int	max_contontac = 8;
	Contact		contacts[max_contontac + 1];
	int			current_index;
};

# endif
