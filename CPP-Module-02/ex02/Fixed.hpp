/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:47:29 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/18 18:34:10 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int _fixed_point;
		static const int _fraction = 8;

	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		~Fixed();
		Fixed(const Fixed& f);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed&		min(Fixed& f1, Fixed& f2);
		static const Fixed&	min(const Fixed& f1, const Fixed& f2);
		static Fixed&		max(Fixed& f1, Fixed& f2);
		static const Fixed&	max(const Fixed& f1, const Fixed& f2);

		Fixed&	operator=(const Fixed& f);
		bool	operator>(const Fixed& f) const;
		bool	operator<(const Fixed& f) const;
		bool	operator>=(const Fixed& f) const;
		bool	operator<=(const Fixed& f) const;
		bool	operator==(const Fixed& f) const;
		bool	operator!=(const Fixed& f) const;
		Fixed	operator+(const Fixed& f);
		Fixed	operator-(const Fixed& f);
		Fixed	operator*(const Fixed& f);
		Fixed	operator/(const Fixed& f);
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);
};

std::ostream& operator<<(std::ostream& o, const Fixed& f);

#endif
