/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   def_phonebook.cpp                                       :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/24 17:29:58 by avaliull            #+#    #+#           */
/*   Updated: 2026/01/24 17:40:32 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::_print_truncated_field(
	std::string field
) {
	if (field.length() >= 10)
	{
		std::string	truncated_field = field;
		truncated_field.resize(10);
		truncated_field[9] = '.';
		std::cout << std::right << std::setw(10) << truncated_field;
	}
	else
		std::cout << std::right << std::setw(10) << field;

}

int	PhoneBook::_input_is_digit(
		std::string str
) {
	if (str.find_first_not_of("0123456789") == std::string::npos)
		return (true);
	return (false);
}

void	PhoneBook::_print_single_contact(
	int contact_index
) {
		std::string *const cur_contact = &contact_list[contact_index].first_name;

		std::cout << std::right << std::setw(10) << contact_index;
		for (int i = 0; i < 3; i++) {
			std::cout << '|';
			_print_truncated_field(cur_contact[i]);
		}
		std::cout << "\n\n";
}

int	PhoneBook::_get_and_validate_input(
	std::string *const field,
	const std::string message
) {
	std::cout << '\n' << message;
	std::getline(std::cin, *field);
	if (field->empty()) {
		std::cout << "Field can't be empty! Try again.\n";
		return (1);
	}
	return (0);
}
