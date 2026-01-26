/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   Account.cpp                                             :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/26 15:43:15 by avaliull            #+#    #+#           */
/*   Updated: 2026/01/26 19:53:46 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

Account::Account(
	int initial_deposit
)
{
	Account::_accountIndex = _nbAccounts;
	Account::makeDeposit(initial_deposit);
}
Account::~Account(
	void
)
{
}


int	Account::getNbAccounts(
	void
) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(
	void
) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(
	void
) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(
	void
) {
	return (Account::_totalNbWithdrawals);
}

void Account::displayStatus(
	void
) const {
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex;
	std::cout << ';';
	std::cout << "amount:" << Account::_amount;
	std::cout << ';';
	std::cout << "created\n";
}

void	Account::makeDeposit(
	int deposit
) {
	Account::_amount += deposit;
	Account::_nbDeposits++;
	Account::_nbAccounts++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

void Account::_displayTimestamp(
	void
)
{
	timespec timestamp;

	timespec_get(&timestamp, TIME_UTC);
	std::cout << "[ " << timestamp.tv_sec << '_' << timestamp.tv_nsec << " ] ";
}

//dummy funcs to make suire it compiles
void	Account::displayAccountsInfos( void ) {
}
int		Account::checkAmount( void ) const {
	return (0);
}
bool	Account::makeWithdrawal( int withdrawal ) {
	return (withdrawal + Account::_nbWithdrawals);
}
Account::Account (void) {
}


//class Account {
//
//
//public:
//
//	typedef Account		t; // why is it just named t what the fucccck
//
//	static int	getNbAccounts( void ); / done
//	static int	getTotalAmount( void ); / done
//	static int	getNbDeposits( void ); / done
//	static int	getNbWithdrawals( void ); / done
//	static void	displayAccountsInfos( void );
//
//	Account( int initial_deposit ); / done?
//	~Account( void ); / done
//
//	void	makeDeposit( int deposit ); / done
//	bool	makeWithdrawal( int withdrawal );
//	int		checkAmount( void ) const;
//	void	displayStatus( void ) const; / done
//
//
//private:
//
//	static int	_nbAccounts;
//	static int	_totalAmount;
//	static int	_totalNbDeposits;
//	static int	_totalNbWithdrawals;
//
//	static void	_displayTimestamp( void ); / done
//
//	int				_accountIndex;
//	int				_amount;
//	int				_nbDeposits;
//	int				_nbWithdrawals;
//
//	Account( void );
//
//};
//
