/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:09:27 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/03 22:45:21 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
}

HumanB::~HumanB()
{

}

void	HumanB::attack()
{
	std::cout << _name << " attacks with their " << _w->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& w)
{
	_w = &w;
}
