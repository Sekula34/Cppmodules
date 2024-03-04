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
}

Account::~Account(void)
{
	_totalAmount -= _amount;
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
}

bool Account::makeWithdrawal(int withdrawal)
{

}