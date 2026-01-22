/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:54:49 by ctaboada          #+#    #+#             */
/*   Updated: 2026/01/22 12:36:44 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_name = name;
    this->is_armed = false;
    std::cout << this->_name << " joined to the battle" << std::endl;
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
    this->is_armed = true;
    std::cout << this->_name << " grabbed a " << this->_weapon->getType() << std::endl;
}

void HumanB::attack()
{
    if(is_armed)
    {
        std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
    }
    else
    {
        std::cout << this->_name << " attacks with his fists" << std::endl;
    }
}