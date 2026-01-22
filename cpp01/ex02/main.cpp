/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:13:43 by ctaboada          #+#    #+#             */
/*   Updated: 2026/01/21 13:35:27 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*		strPTR = &str;
	std::string&		strREF = str;

	std::cout<< "memory address of the string variable: " << &str <<std::endl;
	std::cout<< "memory address held by stringPTR: " << strPTR <<std::endl;
	std::cout<< "memory address held by stringREF: " << &strREF <<std::endl;
	std::cout << std::endl;
	std::cout << "The value of the string variable: "<< str << std::endl;
	std::cout << "The value pointed to by stringPTR: "<< *strPTR << std::endl;
	std::cout << "The value pointed to by stringREF: "<< strREF << std::endl;
}
