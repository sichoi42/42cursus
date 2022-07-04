/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:48:50 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/03 21:50:09 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int N;
	std::cin >> N;
	Zombie	*z = Zombie::zombieHorde(N, "N_zombies");
	delete[] z;
	return (0);
}
