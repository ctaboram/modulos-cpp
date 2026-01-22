/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:08:22 by ctaboada          #+#    #+#             */
/*   Updated: 2026/01/19 11:55:16 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	this->_index = 0;
	std::cout << "Welcome to Crappy! Created an empty phonebook for up to 8 contacts" << std::endl;
}
PhoneBook::~PhoneBook()
{
	std::cout << "Byee!!" << std::endl;
}

static std::string format(const std::string &s)
{
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	return std::string(10 - s.length(), ' ') + s;
}
void	PhoneBook::add()
{
	std::string	str;
	str = "";
	
	if(this->_index >= 8)
		std::cout << "Warning: overwriting contact " << this->_contact[this->_index % 8].get_fname() << std::endl;
	while(!std::cin.eof() && str == "")
	{
		std::cout << "Enter your first name: ";
		if(std::getline(std::cin,str) && str != "")
			this->_contact[this->_index % 8].set_fname(str);
	}
	str = "";
	while(!std::cin.eof() && str == "")
	{
		std::cout << "Enter your last name: ";
		if(std::getline(std::cin,str) && str != "")
			this->_contact[this->_index % 8].set_lname(str);
	}
	str = "";
	while(!std::cin.eof() && str == "")
	{
		std::cout << "Enter your nick name: ";
		if(std::getline(std::cin,str) && str != "")
			this->_contact[this->_index % 8].set_nick(str);
	}
	str = "";
	while(!std::cin.eof() && str == "")
	{
		std::cout << "Enter your phone number: ";
		if(std::getline(std::cin,str) && str != "")
			this->_contact[this->_index % 8].set_phone_n(str);
	}
	str = "";
	while(!std::cin.eof() && str == "")
	{
		std::cout << "Enter your secret: ";
		if(std::getline(std::cin,str) && str != "")
			this->_contact[this->_index % 8].set_secret(str);
	}
	std::cout << "successfully added to phonebook" << std::endl;
	this->_index++;
}
void PhoneBook::search()
{
	int i = 0;
	int max_contacts = (this->_index < 8) ? this->_index : 8;
	std::string input;
	int index;

	if (max_contacts == 0)
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return;
	}

	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	while(i < max_contacts)
	{
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << format(_contact[i].get_fname());
		std::cout << "|" << format(_contact[i].get_lname());
		std::cout << "|" << format(_contact[i].get_nick());
		std::cout << "|" << std::endl;
		i++;
	}

	std::cout << std::endl << "Enter an index: ";
	if (!std::getline(std::cin, input))
	{
		std::cout << std::endl;
		return;
	}

	if (input.length() == 1 && input[0] >= '0' && input[0] <= '8')
	{
		index = input[0] - '0';
		if (index < max_contacts)
		{
			std::cout << std::endl;
			std::cout << "First Name: " << _contact[index].get_fname() << std::endl;
			std::cout << "Last Name: " << _contact[index].get_lname() << std::endl;
			std::cout << "Nickname: " << _contact[index].get_nick() << std::endl;
			std::cout << "Phone Number: " << _contact[index].get_phone_n() << std::endl;
			std::cout << "Darkest Secret: " << _contact[index].get_secret() << std::endl;
		}
		else
			std::cout << "Invalid index! Contact does not exist." << std::endl;
	}
	else
		std::cout << "Invalid input! Please enter a number between 0 and 8." << std::endl;
}