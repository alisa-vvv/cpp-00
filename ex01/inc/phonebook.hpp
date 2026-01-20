/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   phonebook.hpp                                           :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/14 17:45:18 by avaliull            #+#    #+#           */
/*   Updated: 2026/01/20 17:20:48 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# pragma once

class	Contact {
public:
	# define FIELD_COUNT 5
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	secret;
};

class	PhoneBook {
private:
	int			_last_added = -1;
	int			_total_added = 0;

	void	_print_truncated_field(
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

	int	_input_is_digit(
		std::string str
	) {
		if (str.find_first_not_of("0123456789") == std::string::npos)
			return (true);
		return (false);
	}

	void	_print_single_contact(
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

	int	_get_and_validate_input(
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

	const std::string	_input_msg[FIELD_COUNT] = {
		"Enter first name: ",
		"Enter last name: ",
		"Enter nickname: ",
		"Enter phone number: ",
		"Enter darkest secret: "
	};


public:
	# define CONTACT_LIST_SIZE 8
	Contact	contact_list[CONTACT_LIST_SIZE];

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
