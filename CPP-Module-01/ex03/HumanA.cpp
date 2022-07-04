/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:09:27 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/03 22:38:19 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& w) : _w(w), _name(name)
{

}

HumanA::~HumanA()
{

}

void	HumanA::attack()
{
	std::cout << _name << " attacks with their " << _w.getType() << std::endl;
}
