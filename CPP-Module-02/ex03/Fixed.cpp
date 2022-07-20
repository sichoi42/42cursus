/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:50:20 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/16 17:38:08 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point(0)
{

}

Fixed::Fixed(const int i) : _fixed_point(i << Fixed::_fraction)
{

}

Fixed::Fixed(const float f) : _fixed_point(static_cast<int>(roundf(f * (1 << Fixed::_fraction))))
{

}

Fixed::~Fixed()
{

}

Fixed::Fixed(const Fixed& f)
{
	_fixed_point = f._fixed_point;
}

int		Fixed::getRawBits(void) const
{
	return (_fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	_fixed_point = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_fixed_point) / (1 << Fixed::_fraction));
}

int		Fixed::toInt(void) const
{
	return (_fixed_point >> Fixed::_fraction);
}

std::ostream& operator<<(std::ostream& o, const Fixed& f)
{
	return (o << f.toFloat());
}

Fixed& Fixed::operator=(const Fixed& f)
{
	_fixed_point = f.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed& f) const
{
	return (_fixed_point > f.getRawBits());
}

bool	Fixed::operator<(const Fixed& f) const
{
	return (_fixed_point < f.getRawBits());
}

bool	Fixed::operator>=(const Fixed& f) const
{
	return (_fixed_point >= f.getRawBits());
}

bool	Fixed::operator<=(const Fixed& f) const
{
	return (_fixed_point <= f.getRawBits());
}

bool	Fixed::operator==(const Fixed& f) const
{
	return (_fixed_point == f.getRawBits());
}

bool	Fixed::operator!=(const Fixed& f) const
{
	return (_fixed_point != f.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& f)
{
	Fixed temp(this->toFloat() + f.toFloat());
	return (temp);
}

Fixed	Fixed::operator-(const Fixed& f)
{
	Fixed temp(this->toFloat() - f.toFloat());
	return (temp);
}

Fixed	Fixed::operator*(const Fixed& f)
{
	Fixed temp(this->toFloat() * f.toFloat());
	return (temp);
}

Fixed	Fixed::operator/(const Fixed& f)
{
	Fixed temp(this->toFloat() / f.toFloat());
	return (temp);
}

Fixed&	Fixed::operator++(void)
{
	++_fixed_point;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++_fixed_point;
	return (temp);
}

Fixed&	Fixed::operator--(void)
{
	--_fixed_point;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--_fixed_point;
	return (temp);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}
