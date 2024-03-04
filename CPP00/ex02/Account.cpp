#include <iostream>
#include "Account.hpp"


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account:: _totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts ++;
	_totalAmount += initial_deposit;

	std::cout << "<timestamp> ";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	_totalAmount -= _amount;
	std::cout << "<timestamp> ";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	int accounts = Account::getNbAccounts();
	int total = Account::getTotalAmount();
	int deposits = Account::getNbDeposits();
	int withdrawals = Account::getNbWithdrawals();

	std::cout << "<timestamp> ";
	std::cout << "accounts:" << accounts << ";";
	std::cout << "total:" << total <<";";
	std::cout << "deposits:" << deposits <<";";
	std::cout << "withdrawals:" << withdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{

	_amount += deposit;
	_totalNbDeposits ++;
	_nbDeposits ++;

	std::cout << "timestamp";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount - deposit << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if(withdrawal > _amount)
	{
		std::cout << "withdraw time ";
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "p_amount:" << _amount << ";";
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		_amount -= withdrawal;
		_nbWithdrawals ++;
		_totalAmount -= withdrawal;
		std::cout << "withdraw time ";
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "p_amount:" << _amount + withdrawal << ";";
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	}
	return (true);
}

int Account::checkAmount(void) const
{
	std::cout << "Called function checkAmount" << std::endl;
	return (0);
}

void Account::displayStatus(void) const
{
	std::cout << "<timestamp> ";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}
