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

		if (last_added == -1) {
			std::cout << "No contacts!\n";
			return ;
		}
		for (int i = 0; i <= last_added; i++) {
			print_single_contact(i);
		}
		std::cout << "Please enter index of the contact you would like to view: ";
		std::getline(std::cin, contact_index_str);
		contact_index = std::stoi(contact_index_str);
		print_single_contact(contact_index);
	}

	void	DEBUG_list_contacts(void)
	{
		std::cout << "\nDEBUG: list of all contacts so far:\n";
		for (int i = 0; i <= last_added; i++) {
			std::cout << "\tContact #1:\n";
			std::cout << "\t\tFirst name: " << contact_list[i].first_name << '\n';
			std::cout << "\t\tLast name: " << contact_list[i].last_name << '\n';
			std::cout << "\t\tNickname: " << contact_list[i].nickname << '\n';
			std::cout << "\t\tPhone Number: " << contact_list[i].phone_number << '\n';
			std::cout << "\t\tDarkest secret: " << contact_list[i].secret << '\n';
	   }
	}
};
