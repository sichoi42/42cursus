/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:39:10 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/04 17:15:36 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl h;

	h.complain("WARNING");
	h.complain("ERROR");
	h.complain("INFO");
	h.complain("DEBUG");
	return (0);
}
