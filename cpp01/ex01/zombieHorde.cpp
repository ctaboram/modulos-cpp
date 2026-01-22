/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:19:01 by ctaboada          #+#    #+#             */
/*   Updated: 2026/01/21 13:06:49 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if(N <= 0)
		return NULL;
	Zombie	*horde = new Zombie[N];
	int i = 0;
	while(i < N)
	{
		horde[i].set_name(name);
		i++;
	}
	return horde;
}