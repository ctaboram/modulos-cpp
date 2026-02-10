/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:13:18 by ctaboada          #+#    #+#             */
/*   Updated: 2026/02/10 13:22:42 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( const std::string &name) : _name(name), h_points(10), e_points(10), a_damage(0)
{
	std::cout <<"Claptrap " << this->_name <<  " created with default constructor." << std::endl;
}
ClapTrap::ClapTrap(std::string const &name)
{
	std::cout << "Claptrap " << this->_name << "created" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Claptrap"<< this->_name << " copy called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap" << this->_name <<  "destroyed"<< std::endl;
}

void ClapTrap::attack( const std::string &target)
{
	if(this->e_points && this->h_points > 0)
	{
		std::cout << "Claptrap" << this->_name << " attacked " << target << " causing " << this->a_damage << " points of damage" << std::endl;
		this->e_points--;
	}
	if(this->h_points <= 0)
	{
		std::cout << "Claptrap" << this->_name << " is dead!" << std::endl;
	}
	else if(!this->e_points)
		std::cout << "Claptrap" << this->_name << "is out of enegy!"<< std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	
}
