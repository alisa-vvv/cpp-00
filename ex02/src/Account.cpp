/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   Account.cpp                                             :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/26 15:43:15 by avaliull            #+#    #+#           */
/*   Updated: 2026/01/26 20:04:06 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(
	int initial_deposit
) {
	_accountIndex = _nbAccounts;
	makeDeposit(initial_deposit);
	_nbAccounts++;
}

Account::~Account(
	void
) {
	std::cout << "index:" << _accountIndex;
	std::cout << ';';
	std::cout << "amount:" << _amount;
	std::cout << ';';
	std::cout << "closed";
	std::cout << std::endl;
}


int	Account::getNbAccounts(
	void
) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(
	void
) {
	return (_totalAmount);
}

int	Account::getNbDeposits(
	void
) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(
	void
) {
	return (_totalNbWithdrawals);
}

void Account::displayStatus(
	void
) const {
	// it looks like this:
	// if account is just created with no deposits yet, print status + "created"
	// if account has deposts or withdrawals, print status + counts"
	// on destrution, print closed
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ';';
	std::cout << "amount:" << _amount;
	std::cout << ';';
	std::cout << "created\n";
}

void	Account::makeDeposit(
	int deposit
) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ';';
	std::cout << "p_amount:" << _amount;
	std::cout << ';';
	std::cout << "deposit:" << deposit;
	std::cout << ';';
	_amount += deposit;
	std::cout << "amount:" << _amount;
	std::cout << ';';
	_nbDeposits++;
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << ';';
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << std::endl;
}

void Account::_displayTimestamp(
	void
)
{
	timespec timestamp;

	timespec_get(&timestamp, TIME_UTC);
	std::cout << "[ " << timestamp.tv_sec << '_' << timestamp.tv_nsec << " ] ";
}

void	Account::displayAccountsInfos(
	void
) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ';';
	std::cout << "total:" << _totalAmount;
	std::cout << ';';
	std::cout << "deposits:" << _totalNbDeposits;
	std::cout << ';';
	std::cout << "withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}

int		Account::checkAmount( void ) const { // what is that even for i dunno
	return (_amount);
}

bool	Account::makeWithdrawal( int withdrawal ) {
	std::cout << "index:" << _accountIndex;
	std::cout << ';';
	std::cout << "p_amount:" << _amount;
	std::cout << ';';
	std::cout << "withdrawal:";
	_displayTimestamp();
	if (withdrawal > _amount) {
		std::cout << "refused";
		std::cout << std::endl;
		return (false);
	}
	std::cout << withdrawal;
	std::cout << ';';
	_amount -= withdrawal;
	_nbWithdrawals++;
	std::cout << "amount:" << _amount;
	std::cout << ';';
	std::cout << "nb_withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	return (true);
}

Account::Account (void) {
}
