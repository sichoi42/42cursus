/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:11:59 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/04 16:17:38 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

std::string	Replace::preprocess(std::ifstream& fin)
{
	std::stringstream ss;
	ss << fin.rdbuf();
	return (ss.str());
}

void	Replace::stringReplace(std::string *t,
							const std::string& s1, const std::string& s2)
{
	int	len_t = t->length();
	int len_s1 = s1.length();
	while (true)
	{
		size_t crit = (*t).find(s1);
		if (crit == std::string::npos)
			break ;
		std::string	tmp1 = (*t).substr(0, crit);
		std::string	tmp2 = (*t).substr(crit + len_s1, len_t);
		*t = tmp1 + s2 + tmp2;
	}
}
