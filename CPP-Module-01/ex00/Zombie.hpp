/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:45:42 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/03 21:51:39 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(std::string name);
		~Zombie();

		void			announce(void);
		static Zombie	*newZombie(std::string name);
		static void		randomChump(std::string name);
};

#endif
