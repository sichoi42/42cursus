/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:51:08 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/03 21:49:56 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	a = "HI THIS IS BRAIN";
	std::string *ptr = &a;
	std::string& ref = a;

	std::cout << "Memory Address of String Variables" << std::endl;
	std::cout << &a << std::endl;
	std::cout << &ptr << std::endl;
	std::cout << &ref << std::endl;
	std::cout << "Vaule of String Variables" << std::endl;
	std::cout << a << std::endl;
	std::cout << ptr << std::endl;
	std::cout << ref << std::endl;
	return (0);
}
