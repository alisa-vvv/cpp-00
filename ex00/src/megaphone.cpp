/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   megaphone.cpp                                           :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/13 15:46:10 by avaliull            #+#    #+#           */
/*   Updated: 2026/01/13 18:25:42 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(
	int argc,
	char *argv[]
)
{
	std::string	arg_string;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1;
			i < argc;
			i++
		)
		{
			arg_string = argv[i];
			for (std::string::iterator it = arg_string.begin();
				it != arg_string.end();
				it++
			)
				*it = std::toupper(*it);
			std::cout << arg_string;
		}
	}
	std::cout << '\n';
}
