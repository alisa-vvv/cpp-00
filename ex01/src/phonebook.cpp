/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   phonebook.cpp                                           :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/14 16:27:18 by avaliull            #+#    #+#           */
/*   Updated: 2026/01/14 16:29:38 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	print_command_list(void)
{
	std::cout << "\nAvaliable commands:\n\n";
	std::cout << "ADD\tadd a new contact\n";
	std::cout << "SEARCH\tfind a contact\n";
	std::cout << "EXIT\tdestroy all contacts and exit\n\n";
}

int	main(void)
{
	PhoneBook 		*phone_book = new PhoneBook;
	bool			run_program;
	std::string		input_buffer;

	run_program = true;
	std::cout << "\n\tWelcome to the crappy 80's phonebook app!\n\n";
	while (run_program == true)
	{
		print_command_list();
		std::getline(std::cin, input_buffer);
		if (input_buffer == "ADD")
			phone_book->add_contact();
		else if (input_buffer == "SEARCH")
			std::cout << "dummy search\n";
		else if (input_buffer == "EXIT")
		{
			std::cout << "Say goodbye to your contacts!\n";
			run_program = false;
		}
		else if (input_buffer == "DEBUG")
			phone_book->DEBUG_list_contacts();
		else
			std::cout << "\nYou entered a wrong command, you dummy! Here's the list again:\n";
	}
	delete phone_book;
	return (0);
}
