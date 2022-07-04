/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:33:57 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/03 21:51:06 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *Zombie::zombieHorde(int N, std::string name)
{
	Zombie	*z = new Zombie[N];

	for (int i = 0; i < N; ++i)
	{
		std::cout << "Zombie" << i << std::endl;
		z[i]._name = name;
		z[i].announce();
	}
	return (z);
}
