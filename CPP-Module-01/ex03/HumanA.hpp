/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:06:52 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/03 22:26:26 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		Weapon&		_w;
		std::string	_name;

	public:
		HumanA(std::string name, Weapon& w);
		~HumanA();

		void	attack();
};

#endif
