/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:13:47 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/20 14:35:21 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# define Vec Point
# include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point();
		Point(const Fixed x, const Fixed y);
		~Point();
		Point(const Point& p);

		Point&	operator=(const Point& p);
		Fixed	getPointX(void) const;
		Fixed	getPointY(void) const;
		void	setPoint(const Fixed x, const Fixed y);
};

Vec		operator-(const Point& p1, const Point& p2);
Fixed	operator*(const Vec& v1, const Vec& v2);
bool	bsp(Point const a, Point const b, Point const c, Point const point);
#endif
