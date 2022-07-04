/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:04:37 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/03 21:51:19 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z1 = Zombie::newZombie("zombie1");
	Zombie	z2("zombie2");

	z1->announce();
	z2.announce();
	delete z1;
	Zombie::randomChump("zombie3");
	return (0);
}
