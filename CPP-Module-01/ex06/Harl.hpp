/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:19:09 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/04 17:08:24 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

typedef enum harlLevel
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	WRONG
}	Level;

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		Level	hashing(const std::string& filter);
		void	complain(std::string level, std::string& filter);
};

#endif
