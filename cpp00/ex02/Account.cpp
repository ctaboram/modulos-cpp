/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:23:04 by ctaboada          #+#    #+#             */
/*   Updated: 2026/01/19 13:07:13 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;

int Account::_totalAmount = 0;

int Account::_totalNbDeposits = 0;

int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = this->getNbAccounts();
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount();
	std::cout << ";created" << std::endl;
	Account::_nbAccounts++; 
}
Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount();
	std::cout << ";closed" << std::endl;
	Account::_nbAccounts--;
}
int	Account::getNbAccounts()
{
	return(Account::_nbAccounts);
}
int Account::getTotalAmount()
{
	return(Account::_totalAmount);
}
int Account::getNbDeposits()
{
	return(Account::_totalNbDeposits);
}
int Account::getNbWithdrawals()
{
	return(Account::_totalNbWithdrawals);
}
int Account::checkAmount() const
{
	return(this->_amount);
}
void	Account::_displayTimestamp()
{
	time_t now = time(NULL);
	struct tm* lt = localtime(&now);
	char buf[32];
	if (lt && strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", lt))
		std::cout << buf;
	else
		std::cout << "[00000000_000000] ";
}
void	Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:"<< Account::getNbAccounts() << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}
void	Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount();
	std::cout << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
void	Account::makeDeposit( int deposit)
{
	Account::_displayTimestamp();
	int prev = this->_amount;
	int newAmt = prev + deposit;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << prev << ";deposit:" << deposit;
	std::cout << ";amount:" << newAmt << ";nb_deposits:" << (this->_nbDeposits + 1) << std::endl;
	this->_amount = newAmt;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}
bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	int prev = this->_amount;
	if (withdrawal > prev)
	{
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << prev << ";withdrawal:refused" << std::endl;
		return false;
	}
	int newAmt = prev - withdrawal;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << prev << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << newAmt << ";nb_withdrawals:" << (this->_nbWithdrawals + 1) << std::endl;
	this->_amount = newAmt;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return true;
}