/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:06:20 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/03 22:10:55 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		const std::string&	getType();
		void				setType(std::string type);
};

#endif
