/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:22:28 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/20 14:35:02 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{

}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y)
{

}

Point::~Point()
{

}

Point::Point(const Point& p)
{
	const_cast<Fixed&>(_x) = p._x;
	const_cast<Fixed&>(_y) = p._y;
}

Point&	Point::operator=(const Point& p)
{
	if (this != &p)
	{
		const_cast<Fixed&>(_x) = p._x;
		const_cast<Fixed&>(_y) = p._y;
	}
	return (*this);
}

Fixed	Point::getPointX(void) const
{
	return (_x);
}

Fixed	Point::getPointY(void) const
{
	return (_y);
}

void	Point::setPoint(const Fixed x, const Fixed y)
{
	const_cast<Fixed&>(_x) = x;
	const_cast<Fixed&>(_y) = y;
}

Vec	operator-(const Point& p1, const Point& p2)
{
	return (Vec(p1.getPointX() - p2.getPointX(),
		p1.getPointY() - p2.getPointY()));
}

Fixed	operator*(const Vec& v1, const Vec& v2)
{
	return (Fixed(v1.getPointX() * v2.getPointY() - v1.getPointY() * v2.getPointX()));
}
