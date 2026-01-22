/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:54:45 by ctaboada          #+#    #+#             */
/*   Updated: 2026/01/22 12:33:19 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	std::cout << this->_name << " join to the battle with a " << this->_weapon.getType() << " to fight" << std::endl;
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout << this->_name << " atack with his " << this->_weapon.getType() << "." << std::endl; 
}