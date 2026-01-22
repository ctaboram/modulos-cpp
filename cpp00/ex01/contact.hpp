/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:15:03 by ctaboada          #+#    #+#             */
/*   Updated: 2026/01/12 13:32:08 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact{
	private:
		std::string	_fname;	
		std::string	_lname;
		std::string	_nick;
		std::string	_phone_n;	
		std::string	_secret;
	public:
		Contact();
		~Contact();
		std::string get_fname()const;
		std::string get_lname()const;
		std::string get_nick()const;
		std::string get_phone_n()const;
		std::string get_secret()const;
		void	set_fname(std::string	str);
		void	set_lname(std::string	str);
		void	set_nick(std::string	str);
		void	set_phone_n(std::string	str);
		void	set_secret(std::string	str);
};



#endif