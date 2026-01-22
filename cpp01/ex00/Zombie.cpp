/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:13:20 by ctaboada          #+#    #+#             */
/*   Updated: 2026/01/21 12:11:00 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie die!"<< std::endl;
}

void Zombie::announce()
{
	std::cout << name << " :BraiiiiiiinnnzzZ..." << std::endl;
}