/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:13:18 by ctaboada          #+#    #+#             */
/*   Updated: 2026/02/12 12:43:39 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( const std::string &name) : _name(name), h_points(10), e_points(10), a_damage(0)
{
	std::cout <<"ClapTrap " << this->_name <<  " created with default constructor with name." << std::endl;
}
ClapTrap::ClapTrap() : _name("Default"), h_points(10), e_points(10), a_damage(0)
{
    std::cout << "ClapTrap " << this->_name << " created with default constructor." << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap " << this->_name << " copy called" << std::endl;
	*this = other;
}
ClapTrap&  ClapTrap::operator=(const ClapTrap &other)
{
	if(this != &other)
	{
		this->_name = other._name;
		this->h_points = other.h_points;
		this->e_points = other.e_points;
		this->a_damage = other.a_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name <<  " destroyed" << std::endl;
}

void ClapTrap::attack( const std::string &target)
{
	if(this->h_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
		return;
	}
	if(this->e_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " attacked " << target << " causing " << this->a_damage << " points of damage!" << std::endl;
	this->e_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->h_points -= amount;
	if(this->h_points < 0)
		this->h_points = 0;
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage! HP: " << this->h_points << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->e_points > 0 && this->h_points > 0)
	{
		this->h_points += amount;
		this->e_points--;
		std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount << " hit points! HP: " << this->h_points << std::endl;
	}
	else if(this->h_points <= 0)
		std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " is out of energy!" << std::endl;
}
