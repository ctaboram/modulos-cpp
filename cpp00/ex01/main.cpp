/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:55:13 by ctaboada          #+#    #+#             */
/*   Updated: 2026/01/19 11:26:04 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void)
{
	PhoneBook	b1;
	std::string	str;

	while(str != "EXIT")
	{
		std::cout << "Enter a comand > ";
		if(!std::getline(std::cin,str))
		{
			std::cout << std::endl;
			break;
		}
		if(str == "ADD")
			b1.add();
		else if(str == "SEARCH")
			b1.search();
		else
		{
			std::cout << "_________________________________________________\n" << std::endl;
			std::cout << "Comand not found, please try ADD, SEARCH or EXIT" << std::endl;
		}
	}
	return 0;
}