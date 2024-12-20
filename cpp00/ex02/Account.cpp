#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

 int Account::_nbAccounts = 0;
 int Account::_totalAmount = 0;
 int Account::_totalNbDeposits = 0;
 int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return Account::_totalNbWithdrawals;
}

void    Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << " accounts:" << Account::_nbAccounts << ";total:" 
        << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits
        << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

Account::Account(int deposit)
{
    _amount = deposit;
    Account::_totalAmount += _amount;
    _accountIndex = Account::_nbAccounts++;
    _nbDeposits = 0;
    // Account::_totalNbDeposits++;
    _nbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex <<";amount:" << this->_amount 
        <<";created" << std::endl;
}

Account::Account(void)
{
    _accountIndex = Account::_nbAccounts++;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
}

void    Account::makeDeposit(int deposit)
{
    int p_amount;

    p_amount = _amount;
    _amount += deposit;
    _nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_displayTimestamp();
    std::cout<< " index:" << this->_accountIndex << ";p_amount:" << p_amount
        << ";deposit:" << deposit << ";amount:" << _amount
        << ";nb_deposits:" << this->_nbDeposits <<std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    int p_amount;

    p_amount = _amount;
    Account::_displayTimestamp();
	if (this->checkAmount() > withdrawal)
    {
        _amount -= withdrawal;
        _nbWithdrawals++;
        Account::_totalAmount -= withdrawal;
        Account::_totalNbWithdrawals++;
        std::cout << " index:" <<this->_accountIndex << ";p_amount:" << p_amount
         << ";withdrawal:" << withdrawal <<";amount:" << this->_amount 
        << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
        return true;
    }
    std::cout << " index:" << _accountIndex <<";p_amount:" << p_amount 
        << ";withdrawal:refused\n";
	return false;
}

int Account::checkAmount(void) const
{
    // std::cout << "\nin\n";
    return (this->_amount);

}

void Account::_displayTimestamp(void)
{
    // Get current time
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    // Format the time
    std::ostringstream oss;
    oss << std::put_time(localTime, "%Y%m%d_%H%M%S");
    std::cout << "[" << oss.str() << "] ";
}

void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount 
        << ";deposits:" << this->_nbDeposits << ";withdrawals:" 
        << this->_nbWithdrawals << std::endl;
}

Account::~Account(void)
{
    Account::_nbAccounts--;
    Account::_totalAmount -= this->_amount;
    Account::_totalNbWithdrawals -= this->_nbWithdrawals;
    Account::_totalNbDeposits -= this->_nbDeposits;
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_accountIndex = 0;
    Account::_displayTimestamp();
    std::cout << " index:" << _accountIndex <<";amount:" << _amount << ";closed\n";
}