/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:06:52 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/03 22:44:45 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		Weapon		*_w;
		std::string	_name;

	public:
		HumanB(std::string name);
		~HumanB();

		void	attack();
		void	setWeapon(Weapon& w);
};

#endif
