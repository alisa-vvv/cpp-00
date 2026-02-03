/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   PhoneBook.cpp                                           :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/24 17:29:58 by avaliull            #+#    #+#           */
/*   Updated: 2026/02/03 17:07:04 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void	PhoneBook::_print_truncated_field(
	const std::string&	field
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

int	PhoneBook::_index_is_valid(
	std::string	str
) {
	if (!str.empty()
		&& str.find_first_not_of("0123456789") == std::string::npos)
		return (true);
	return (false);
}

void	PhoneBook::_print_single_contact(
	int	contact_index
) {
	_print_truncated_field(std::to_string(contact_index));
	std::cout << '|';
	_print_truncated_field(contact_list[contact_index].getRefFirstName());
	std::cout << '|';
	_print_truncated_field(contact_list[contact_index].getRefLastName());
	std::cout << '|';
	_print_truncated_field(contact_list[contact_index].getRefNickName());
	std::cout << '|';
	_print_truncated_field(contact_list[contact_index].getRefPhoneNum());
	std::cout << "\n\n";
}

void	PhoneBook::_print_contact_full(
	int	contact_index
) {
	std::cout << '\n';
	std::cout << "First name: ";
	std::cout << contact_list[contact_index].getRefFirstName();
	std::cout << '\n';
	std::cout << "Last name: ";
	std::cout << contact_list[contact_index].getRefLastName();
	std::cout << '\n';
	std::cout << "Nickname: ";
	std::cout << contact_list[contact_index].getRefNickName();
	std::cout << '\n';
	std::cout << "Phone number: ";
	std::cout << contact_list[contact_index].getRefPhoneNum();
	std::cout << '\n';
	std::cout << "Darkest secret: ";
	std::cout << contact_list[contact_index].getRefSecret();
	std::cout << "\n\n";
}

int	PhoneBook::_get_and_validate_input(
	std::string&		field,
	const std::string	message
) {
	bool	got_valid_input = false;

	while (got_valid_input == false) {
		field.clear();
		std::cout << '\n' << message;
		if (!std::getline(std::cin, field)) {
			return (1);
		}
		else if (_all_symbols_are_valid(field) == false) {
			std::cout << "Can only use alphanumeric symbols, spaces, dashes and apostrophes. Try again.\n";
		}
		else if (field.length() > 127) {
			std::cout << "Field can't be longer than 127 characters! Try again.\n";
		}
		else if (field.empty()) {
			std::cout << "Field can't be empty! Try again.\n";
		}
		else
			got_valid_input = true;
	}
	return (0);
}

bool	PhoneBook::_all_symbols_are_valid(
	const	std::string&	str
) {
	size_t	i;

	for (i = 0; i < str.length(); i++) {
		if ((str[i] < 'A' || str[i] > 'Z')
			&& (str[i] < 'a' || str[i] > 'z')
			&& (str[i] < '0' || str[i] > '9')
			&& str[i] != ' ' && str[i] != '-' && str[i] != '`')
			return (false);
	}
	return (true);
}


void	PhoneBook::add_contact(
	void
) {
	std::string	input_str;

	if (_last_added == 7)
		_last_added = 0;
	else
		_last_added++;
	if (_get_and_validate_input(input_str, "Enter first name: ") == 1)
		return ;
	contact_list[_last_added].insertName(input_str);
	if (_get_and_validate_input(input_str, "Enter last name: ") == 1)
		return ;
	contact_list[_last_added].insertLastName(input_str);
	if (_get_and_validate_input(input_str, "Enter nickname: ") == 1)
		return ;
	contact_list[_last_added].insertNickName(input_str);
	if (_get_and_validate_input(input_str, "Enter phone number: ") == 1)
		return ;
	contact_list[_last_added].insertPhoneNum(input_str);
	if (_get_and_validate_input(input_str, "Enter darkest secret: ") == 1)
		return ;
	contact_list[_last_added].insertSecret(input_str);
	if (_total_added < 8)
		_total_added++;
	std::cout << "\nContact added!\n";
}

void	PhoneBook::search_contact(
	void
)
{
	int			contact_index;
	std::string	contact_index_str;

	if (_total_added == 0) {
		std::cout << "No contacts!\n";
		return ;
	}
	for (int i = 0; i < _total_added; i++) {
		_print_single_contact(i);
	}
	std::cout << "Please enter index of the contact you would like to view: \n";
	std::cout << "index: ";
	if (!std::getline(std::cin, contact_index_str))
		return ;
	if (_index_is_valid(contact_index_str) == false) {
		std::cout << "\nIndex can only be a positive number!\n";
		std::cout << "SEARCH again and input a correct index.\n\n";
		return ;
	}
	contact_index = std::stoi(contact_index_str);
	if (contact_index >= _total_added || contact_index < 0) {
		std::cout << "\nIndex out of range!\n";
		std::cout << "SEARCH again and input a correct index.\n\n";
		return ;
	}
	_print_contact_full(contact_index);
}
