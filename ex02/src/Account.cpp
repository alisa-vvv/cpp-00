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

using std::cout;
using std::endl;

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(
	int initial_deposit
) {
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = initial_deposit;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	cout << "index:" << _accountIndex;
	cout << ';';
	cout << "amount:" << _amount;
	cout << ';';
	cout << "created\n";
}

Account::Account(
	void
) {
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = 0;
	_nbAccounts++;
}


Account::~Account(
	void
) {
	_displayTimestamp();
	cout << "index:" << _accountIndex;
	cout << ';';
	cout << "amount:" << _amount;
	cout << ';';
	cout << "closed";
	cout << endl;
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
	_displayTimestamp();
	cout << "index:" << _accountIndex;
	cout << ';';
	cout << "amount:" << _amount;
	cout << ';';
	cout << "deposits:" << _nbDeposits;
	cout << ';';
	cout << "withdrawals:" << _nbWithdrawals;
	cout << endl;
}

void	Account::makeDeposit(
	int deposit
) {
	_displayTimestamp();
	cout << "index:" << _accountIndex;
	cout << ';';
	cout << "p_amount:" << _amount;
	cout << ';';
	cout << "deposit:" << deposit;
	cout << ';';
	_amount += deposit;
	cout << "amount:" << _amount;
	cout << ';';
	_nbDeposits++;
	cout << "nb_deposits:" << _nbDeposits;
	_totalNbDeposits++;
	_totalAmount += deposit;
	cout << endl;
}

void Account::_displayTimestamp(
	void
)
{
	timespec timestamp;

	timespec_get(&timestamp, TIME_UTC);
	cout << "[" << timestamp.tv_sec << '_' << timestamp.tv_nsec << "] ";
}

void	Account::displayAccountsInfos(
	void
) {
	_displayTimestamp();
	cout << "accounts:" << _nbAccounts;
	cout << ';';
	cout << "total:" << _totalAmount;
	cout << ';';
	cout << "deposits:" << _totalNbDeposits;
	cout << ';';
	cout << "withdrawals:" << _totalNbWithdrawals;
	cout << endl;
}

int		Account::checkAmount(
	void
) const {
	return (_amount);
}

bool	Account::makeWithdrawal(
	int withdrawal
) {
	_displayTimestamp();
	cout << "index:" << _accountIndex;
	cout << ';';
	cout << "p_amount:" << _amount;
	cout << ';';
	cout << "withdrawal:";
	if (withdrawal > _amount) {
		cout << "refused";
		cout << endl;
		return (false);
	}
	cout << withdrawal;
	cout << ';';
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	cout << "amount:" << _amount;
	cout << ';';
	cout << "nb_withdrawals:" << _nbWithdrawals;
	cout << endl;
	return (true);
}
