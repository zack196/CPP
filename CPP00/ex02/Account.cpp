/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:48:02 by zel-oirg          #+#    #+#             */
/*   Updated: 2025/01/11 17:25:20 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( void )
{
	_accountIndex = Account::getNbAccounts();
    _nbAccounts++;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += _amount;
}

int	Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
    return _totalAmount;
}

int	Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

Account::Account( int initial_deposit )
{
    Account::_displayTimestamp();
	_accountIndex = Account::getNbAccounts();
    _nbAccounts++;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += _amount;
    std::cout << "index:" << _accountIndex <<";amount:"<< _amount
        <<";created" << std::endl;
}


Account::~Account()
{
    Account::_displayTimestamp();
    std::cout << "index:"<<_accountIndex <<";amount:" << _amount 
        << ";closed" << std::endl;
}

void	Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:"<< Account::getNbAccounts() <<";total:" << Account::getTotalAmount() 
        << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals();
    std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
    int p_amount;

    p_amount = _amount;
    
    Account::_displayTimestamp();
    _amount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount 
        << ";deposit:" << deposit <<";amount:" << _amount << ";nb_deposits:" 
        << _nbDeposits; 
    std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    int p_amount;

    Account::_displayTimestamp();
    p_amount = _amount;
    std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:";
    if (checkAmount() < withdrawal)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" 
    << _nbWithdrawals << std::endl; 
    return true;
}

int	Account::checkAmount( void ) const 
{
    return _amount;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" 
        << _nbDeposits <<";withdrawals:" << _nbWithdrawals;
    std::cout << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t  time_stamp = time(NULL);
    struct tm date_time = *localtime(&time_stamp);
    
    std::cout << "[";

    std::cout << 1900 + date_time.tm_year;

    if ((1 + date_time.tm_mon) / 10 == 0)
        std::cout << "0";
    std::cout << 1 + date_time.tm_mon;

    if (date_time.tm_mday / 10 == 0)
        std::cout << "0";
    std::cout << date_time.tm_mday;
    
    std::cout << "_";

    if (date_time.tm_hour / 10 == 0)
        std::cout << "0";
    std::cout << date_time.tm_hour;

    if (date_time.tm_min / 10 == 0)
        std::cout << "0";
    std::cout << date_time.tm_min;

    if (date_time.tm_sec / 10 == 0)
        std::cout << "0";
    std::cout << date_time.tm_sec;

    std::cout << "] ";
}
