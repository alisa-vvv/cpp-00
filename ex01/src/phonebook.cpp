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

void	print_left_align(
	std::string	str
) {
	std::cout << std::left << std::setw(10) << str;
}

void	print_command_list(
	void
) {
	std::cout << "\nAvaliable commands:\n\n";
	print_left_align("ADD");
	std::cout << "add a new contact\n";
	print_left_align("SEARCH");
	std::cout << "find a contact\n";
	print_left_align("EXIT");
	std::cout << "destroy all contacts and exit\n\n";
}

void	run_method(
	PhoneBook 		*phone_book,
	bool			*do_run_program,
	std::string		input_buffer
) {
	if (input_buffer == "ADD")
		phone_book->add_contact();
	else if (input_buffer == "SEARCH")
		phone_book->search_contact();
	else if (input_buffer == "EXIT") {
		std::cout << "Say goodbye to your contacts!\n";
		*do_run_program = false;
	}
}

int	main(
	void
) {
	PhoneBook 		*phone_book = new PhoneBook;
	bool			do_run_program;
	std::string		input_buffer;

	do_run_program = true;
	std::cout << "\n\tWelcome to the crappy 80's phonebook app!\n\n";
	print_command_list();
	while (do_run_program == true) {
		std::cout << "Enter command: ";
		std::getline(std::cin, input_buffer);
		std::cout << '\n';
		run_method(phone_book, &do_run_program, input_buffer);
	}
	delete phone_book;
	return (0);
}
