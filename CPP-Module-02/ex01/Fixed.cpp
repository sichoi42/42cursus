/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:50:20 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/16 15:55:49 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) : _fixed_point(i << Fixed::_fraction)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _fixed_point(static_cast<int>(roundf(f * (1 << Fixed::_fraction))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f)
{
	std::cout << "Copy constructor called" << std::endl;
	_fixed_point = f._fixed_point;
}

Fixed& Fixed::operator=(const Fixed& f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_fixed_point = f.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
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
