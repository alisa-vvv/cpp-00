/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   phonebook.hpp                                           :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/14 17:45:18 by avaliull            #+#    #+#           */
/*   Updated: 2026/01/24 17:38:39 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# pragma once

# define FIELD_COUNT 5
class	Contact {
public:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	secret;
};

# define PHONEBOOK_MAX_SIZE 8
class	PhoneBook {
private:
	int			_last_added = -1;
	int			_total_added = 0;

	void	_print_truncated_field(
		std::string field
	);

	int	_input_is_digit(
		std::string str
	);

	void	_print_single_contact(
		int contact_index
	);

	int	_get_and_validate_input(
		std::string *const field,
		const std::string message
	);

	const std::string	_input_msg[FIELD_COUNT] = {
		"Enter first name: ",
		"Enter last name: ",
		"Enter nickname: ",
		"Enter phone number: ",
		"Enter darkest secret: "
	};

public:
	Contact	contact_list[PHONEBOOK_MAX_SIZE];

	void	add_contact(void) {
		if (_last_added == 7)
			_last_added = 0;
		else
			_last_added++;
		std::string *const cur_contact = &contact_list[_last_added].first_name;

		for (int i = 0; i < FIELD_COUNT; i++) {
			while (_get_and_validate_input(&cur_contact[i], _input_msg[i]) != 0) {
				;
			}
		}
		if (_total_added < 8)
			_total_added++;
		std::cout << "\nContact added!\n";
	};

	void	search_contact(void)
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
		std::getline(std::cin, contact_index_str);
		if (_input_is_digit(contact_index_str) == false) {
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
		_print_single_contact(contact_index);
	}
};

#endif /*PHONEBOOK_H*/
