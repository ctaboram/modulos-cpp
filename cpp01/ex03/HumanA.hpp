/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:54:47 by ctaboada          #+#    #+#             */
/*   Updated: 2026/01/22 12:32:51 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A
#define HUMAN_A

#include "Weapon.hpp"
#include <iostream>
class HumanA
{
private:
    std::string _name;
    Weapon& _weapon;  // Referencia, no copia
public:
    HumanA(std::string name, Weapon& weapon);  // Referencia en constructor
    ~HumanA();
    void attack();
};


#endif
