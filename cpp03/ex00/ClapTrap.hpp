/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:13:20 by ctaboada          #+#    #+#             */
/*   Updated: 2026/02/10 13:11:11 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

#include <string>
#include <iostream>

class ClapTrap
{
private:
	std::string	_name;
	int h_points;
	int e_points;
	int a_damage;
	
public:
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);
	ClapTrap& operator=(const ClapTrap &other);
	~ClapTrap();
	
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void takeDamage(unsigned int amount);
};

#endif