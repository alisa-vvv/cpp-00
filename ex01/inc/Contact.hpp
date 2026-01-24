/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   Contact.hpp                                             :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/24 17:45:56 by avaliull            #+#    #+#           */
/*   Updated: 2026/01/24 17:46:47 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef CONTACT_H
# define CONTACT_H
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

#endif
