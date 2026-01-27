/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   PhoneBook.hpp                                           :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/14 17:45:18 by avaliull            #+#    #+#           */
/*   Updated: 2026/01/24 18:15:12 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Contact.hpp"

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# pragma once

# define PHONEBOOK_MAX_SIZE 8

class Contact;

class	PhoneBook {
public:
	Contact	contact_list[PHONEBOOK_MAX_SIZE];

	void	add_contact(
		void
	);

	void	search_contact(
		void
	);

private:
	int			_last_added = -1;
	int			_total_added = 0;

	void	_print_truncated_field(
		std::string	field
	);

	int	_input_is_digit(
		std::string	str
	);

	void	_print_single_contact(
		int	contact_index
	);

	int	_get_and_validate_input(
		std::string *const	field,
		const std::string	message
	);

	const std::string	_input_msg[FIELD_COUNT] = {
		"Enter first name: ",
		"Enter last name: ",
		"Enter nickname: ",
		"Enter phone number: ",
		"Enter darkest secret: "
	};

};

#endif /*PHONEBOOK_H*/
