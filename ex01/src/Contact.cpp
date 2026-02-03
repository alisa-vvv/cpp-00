/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   Contact.cpp                                             :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/02/03 13:03:27 by avaliull            #+#    #+#           */
/*   Updated: 2026/02/03 14:37:33 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Contact.hpp"

const std::string&	Contact::getRefFirstName() {
	return (first_name);
}

const std::string&	Contact::getRefLastName() {
	return (last_name);
}

const std::string&	Contact::getRefNickName() {
	return (nickname);
}

const std::string&	Contact::getRefPhoneNum() {
	return (phone_number);
}

const std::string&	Contact::getRefSecret() {
	return (secret);
}

void	Contact::insertName(
	const std::string& value
) {
	first_name = value;
}
void	Contact::insertLastName(
	const std::string& value
) {
	last_name = value;
}
void	Contact::insertNickName(
	const std::string& value
) {
	nickname = value;
}
void	Contact::insertPhoneNum(
	const std::string& value
) {
	phone_number = value;
}
void	Contact::insertSecret(
	const std::string& value
) {
	secret = value;
}




//const std::string&	Contact::getRefLastName();
//const std::string&	Contact::getRefNickName();
//const std::string&	Contact::getRefPhoneNum();
//const std::string&	Contact::getRefSecret();
