/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:13:22 by ctaboada          #+#    #+#             */
/*   Updated: 2026/02/12 12:44:58 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "=== Robot 1 ===" << std::endl;
	ClapTrap robot1("pepito");
	robot1.attack("Enemy");
	robot1.takeDamage(3);
	robot1.beRepaired(2);
	std::cout << std::endl;

	std::cout << "=== Robot 2 ===" << std::endl;
	ClapTrap robot2("manolin");
	robot2.attack("Droid");
	robot2.takeDamage(8);
	std::cout << std::endl;

	std::cout << "=== assignment (robot2 = robot1) ===" << std::endl;
	robot2 = robot1;
	robot2.attack("Target");
	std::cout << std::endl;

	std::cout << "=== Robot 3 (death) ===" << std::endl;
	ClapTrap robot3("albertillo");
	robot3.takeDamage(15);
	robot3.attack("Nothing");
	robot3.beRepaired(5);
	std::cout << std::endl;

	std::cout << "=== End ===" << std::endl;
	return 0;
}
