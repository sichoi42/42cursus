/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:06:03 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/03 22:23:12 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{

}

Weapon::Weapon(std::string type)
{
	_type = type;
}

Weapon::~Weapon()
{

}

const std::string&	Weapon::getType()
{
	return (_type);
}

void	Weapon::setType(std::string type)
{
	_type = type;
}
