/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:11:04 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/04 15:53:39 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <fstream>
# include <sstream>
# include <iostream>

class Replace
{
	private:

	public:
		Replace();
		~Replace();

		static std::string	preprocess(std::ifstream& fin);
		static void			stringReplace(std::string *t,
								const std::string& s1, const std::string& s2);
};

#endif
