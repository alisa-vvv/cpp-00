/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   Contact.hpp                                             :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/24 17:45:56 by avaliull            #+#    #+#           */
/*   Updated: 2026/02/03 14:46:41 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef CONTACT_H
# define CONTACT_H
# pragma once

# define FIELD_COUNT 5
class	Contact {
public:
	const std::string&	getRefFirstName();
	const std::string&	getRefLastName();
	const std::string&	getRefNickName();
	const std::string&	getRefPhoneNum();
	const std::string&	getRefSecret();
	
	void	insertName(
		const std::string& value
	);
	void	insertLastName(
		const std::string& value
	);
	void	insertNickName(
		const std::string& value
	);
	void	insertPhoneNum(
		const std::string& value
	);
	void	insertSecret(
		const std::string& value
	);


private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	secret;
};

#endif /*ifndef CONTACT_H*/
