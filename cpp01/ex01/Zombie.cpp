/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:18:13 by ctaboada          #+#    #+#             */
/*   Updated: 2026/01/21 13:11:24 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "";
	std::cout <<"zombie is created" << std::endl;
}

Zombie::Zombie( std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie die!"<< std::endl;
}
void Zombie::set_name(std::string name)
{
	this->name = name;
}

void Zombie::announce()
{
	std::cout << name << " :BraiiiiiiinnnzzZ..." << std::endl;
}