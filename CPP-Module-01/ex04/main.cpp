/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:51:17 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/04 16:16:17 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Replace.hpp"

void	exitFatal(const std::string& s)
{
	std::cerr << s << std::endl;
	std::exit(1);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		exitFatal("Wrong Arguments!!");
	std::ifstream	fin(argv[1], std::ios_base::in);
	std::ofstream	fout(static_cast<std::string>(argv[1]) + ".replace");

	if (!fin.good() || !fout.good())
		exitFatal("Corrupted File!!");
	std::string s = Replace::preprocess(fin);
	Replace::stringReplace(&s, argv[2], argv[3]);
	fout << s;
	fin.close();
	fout.close();
	return (0);
}
