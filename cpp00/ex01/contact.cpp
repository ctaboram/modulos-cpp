/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:03:56 by ctaboada          #+#    #+#             */
/*   Updated: 2026/01/19 11:14:18 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact(){
	
}
Contact::~Contact(){
	
}
std::string Contact::get_fname() const
{
	return(this->_fname);
}
std::string Contact::get_lname() const
{
	return(this->_lname);
}
std::string Contact::get_nick() const
{
	return(this->_nick);
}
std::string Contact::get_phone_n() const
{
	return(this->_phone_n);
}
std::string Contact::get_secret() const
{
	return(this->_secret);
}
void	Contact::set_fname(std::string str)
{
	this->_fname = str;
}
void	Contact::set_lname(std::string str)
{
	this->_lname = str;
}
void	Contact::set_nick(std::string str)
{
	this->_nick = str;
}
void	Contact::set_phone_n(std::string str)
{
	this->_phone_n = str;
}
void	Contact::set_secret(std::string str)
{
	this->_secret = str;
}