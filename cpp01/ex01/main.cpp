/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:18:28 by ctaboada          #+#    #+#             */
/*   Updated: 2026/01/21 13:11:33 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int N = 10;
	
	Zombie	*horde = zombieHorde(N, "zombieHorde");
	int i = 0;
	while(i < N)
	{
		horde[i].announce();
		i++;	
	}
	delete[] horde;
	return 0;
}