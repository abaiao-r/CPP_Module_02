/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:34:30 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/09/13 20:55:13 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"


Point::Point(void) : x(0), y(0)
{
}

Point::Point(const Point &src) : x(src.x), y(src.y)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::~Point(void)
{
}

Point &Point::operator=(const Point &src)
{
    (void)src;
    return (*this);
}

Fixed Point::getX(void) const
{
    return (this->x);
}

Fixed Point::getY(void) const
{
    return (this->y);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed const x = point.getX();
    Fixed const y = point.getY();

    Fixed const x1 = a.getX();
    Fixed const y1 = a.getY();
    Fixed const x2 = b.getX();
    Fixed const y2 = b.getY();
    Fixed const x3 = c.getX();
    Fixed const y3 = c.getY();

    Fixed const a1 = ((y2 - y1) * (x - x1)) - ((x2 - x1) * (y - y1));
    Fixed const a2 = ((y3 - y2) * (x - x2)) - ((x3 - x2) * (y - y2));
    Fixed const a3 = ((y1 - y3) * (x - x3)) - ((x1 - x3) * (y - y3));

    if ((a1 > 0 && a2 > 0 && a3 > 0) || (a1 < 0 && a2 < 0 && a3 < 0))
    {
        std::cout << "True" << std::endl;
        return (true);
    }
    std::cout << "False" << std::endl;
    return (false);
}