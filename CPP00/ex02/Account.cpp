#include <iostream>
#include <ctime>
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

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	_totalAmount -= _amount;
	_displayTimestamp();
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

	_displayTimestamp();
	std::cout << "accounts:" << accounts << ";";
	std::cout << "total:" << total <<";";
	std::cout << "deposits:" << deposits <<";";
	std::cout << "withdrawals:" << withdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{

	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits ++;
	_nbDeposits ++;

	_displayTimestamp();
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
		_displayTimestamp();
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
		_totalNbWithdrawals ++;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "p_amount:" << _amount + withdrawal << ";";
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << _amount << ";";
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
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t current  = std::time(NULL);
	std::tm* time_pointer = std::localtime(&current);
	
	char buffer[16];
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", time_pointer);

	std::cout << "["<< buffer <<"] ";
}
