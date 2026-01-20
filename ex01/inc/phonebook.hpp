/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   phonebook.hpp                                           :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/14 17:45:18 by avaliull            #+#    #+#           */
/*   Updated: 2026/01/14 18:01:41 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

class	Contact {
public:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	secret;
};

class	PhoneBook {

private:
	int	last_added = -1;
	int	total_added = 0;

	void	print_truncated_field(
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

	int	input_is_digit(
		std::string str
	) {
		if (str.find_first_not_of("0123456789") == std::string::npos)
			return (true);
		return (false);
	}

	void	print_single_contact(
		int contact_index
	) {
			std::cout << std::right << std::setw(10) << contact_index;
			std::cout << '|';
			print_truncated_field(contact_list[contact_index].first_name);
			std::cout << '|';
			print_truncated_field(contact_list[contact_index].last_name);
			std::cout << '|';
			print_truncated_field(contact_list[contact_index].nickname);
			std::cout << "\n\n";
	}

public:
	Contact	contact_list[8];

	void	add_contact(void) {
		if (last_added == 7)
			last_added = 0;
		else
			last_added++;
		if (total_added < 8)
			total_added++;
		// todo: add check for empty strings
		std::cout << "\nEnter first name: ";
		std::getline(std::cin, contact_list[last_added].first_name);
		std::cout << "\nEnter last name: ";
		std::getline(std::cin, contact_list[last_added].last_name);
		std::cout << "\nEnter nickname: ";
		std::getline(std::cin, contact_list[last_added].nickname);
		std::cout << "\nEnter phone number: ";
		std::getline(std::cin, contact_list[last_added].phone_number);
		std::cout << "\nEnter darkest secret: ";
		std::getline(std::cin, contact_list[last_added].secret);
		std::cout << "\nContact added!\n";
	};

	void	search_contact(void)
	{
		int			contact_index;
		std::string	contact_index_str;

		if (total_added == 0) {
			std::cout << "No contacts!\n";
			return ;
		}
		for (int i = 0; i < total_added; i++) {
			print_single_contact(i);
		}
		std::cout << "Please enter index of the contact you would like to view: \n";
		std::cout << "index: ";
		std::getline(std::cin, contact_index_str);
		if (input_is_digit(contact_index_str) == false) {
			std::cout << "\nIndex can only be a positive number!\n";
			std::cout << "SEARCH again and input a correct index.\n\n";
			return ;
		}
		contact_index = std::stoi(contact_index_str);
		if (contact_index >= total_added || contact_index < 0)
		{
			std::cout << "\nIndex out of range!\n";
			std::cout << "SEARCH again and input a correct index.\n\n";
			return ;
		}
		print_single_contact(contact_index);
	}
};
