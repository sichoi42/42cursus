/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:39:10 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/04 17:15:17 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong Arguments!!" << std::endl;
		return (1);
	}
	Harl h;
	std::string	filter = static_cast<std::string>(argv[1]);

	h.complain("WARNING", filter);
	h.complain("ERROR", filter);
	h.complain("INFO", filter);
	h.complain("DEBUG", filter);
	return (0);
}
