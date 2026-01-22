/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:14:54 by ctaboada          #+#    #+#             */
/*   Updated: 2026/01/12 12:08:36 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac,char **av)
{
	int	j;
	int	i;
	
	i = 1;
	if(ac > 1)
	{
		while(i < ac)
		{
			j = 0;
			while(av[i][j] != '\0')
			{
				std::cout << (char)toupper(av[i][j]);
				j++;
			}
			if(av[i][j] == '\0')
				std::cout << " ";
			i++;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	return 0;
}