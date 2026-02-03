/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   PhoneBook.hpp                                           :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/14 17:45:18 by avaliull            #+#    #+#           */
/*   Updated: 2026/02/03 16:57:26 by avaliull            ########   odam.nl   */
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
	void	add_contact(
		void
	);

	void	search_contact(
		void
	);

private:
	Contact	contact_list[PHONEBOOK_MAX_SIZE];

	int			_last_added = -1;
	int			_total_added = 0;

	void	_print_truncated_field(
		const std::string&	field
	);

	int	_index_is_valid(
		std::string	str
	);

	void	_print_single_contact(
		int	contact_index
	);

	void	_print_contact_full(
		int	contact_index
	);

	int	_get_and_validate_input(
		std::string&		field,
		const std::string	message
	);

	bool	_all_symbols_are_valid(
		const	std::string&	str
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
