/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:47:29 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/18 18:34:34 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	private:
		int _fixed_point;
		static const int _fraction = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& f);
		Fixed& operator=(const Fixed& f);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
