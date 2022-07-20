/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:19:50 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/20 14:40:09 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point a(1, 2);
	Point b(0, 0);
	Point c(2, 0);
	Point p(1, 1);

	std::cout << (p - a) * (b - a) << std::endl;
	std::cout << (p - b) * (c - b) << std::endl;
	std::cout << (p - c) * (a - c) << std::endl;
	std::cout << bsp(a, b, c, p) << std::endl;
	return (0);
}
