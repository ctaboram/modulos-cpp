/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:39:09 by ctaboada          #+#    #+#             */
/*   Updated: 2026/01/12 13:27:50 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iomanip>
#include "contact.hpp"


class PhoneBook{
	private:
		Contact	_contact[8];
		int	_index;
		bool _fulll;
	public:
		PhoneBook();
		~PhoneBook();
		void add();
		void search();
		void print(Contact contact);
		Contact get_contact(int index);
};
#endif