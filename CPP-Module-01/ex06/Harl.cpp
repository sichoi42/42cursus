/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:28:25 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/04 17:12:39 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my "
			<< "7XL-double-cheese-triple-pickle-specialketchup burger. "
			<< "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
			<< "You didn’t put enough bacon in my burger! "
			<< "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cerr <<  "I think I deserve to have some extra bacon for free. "
			<< "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cerr << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Level	Harl::hashing(const std::string& filter)
{
	if (filter == "DEBUG")
		return (DEBUG);
	else if (filter == "INFO")
		return (INFO);
	else if (filter == "WARNING")
		return (WARNING);
	else if (filter == "ERROR")
		return (ERROR);
	else
		return (WRONG);
}
void	Harl::complain(std::string level, std::string& filter)
{
	void (Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	message[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	Level l = hashing(filter);
	for (int i = 0; i < 4; ++i)
	{
		if (i >= l && level == message[i])
		{
			std::cout << "[ " << level << " ]" << std::endl;
			(this->*ptr[i])();
		}
	}
}
