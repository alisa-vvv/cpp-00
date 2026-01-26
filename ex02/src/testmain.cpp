/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   testmain.cpp                                            :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/26 19:43:02 by avaliull            #+#    #+#           */
/*   Updated: 2026/01/26 19:59:18 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <functional>

int	main(void)
{
	Account new_acc = Account(123);

	std::mem_fn( &Account::displayStatus );
}
