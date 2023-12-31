/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:34:30 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/09/15 14:11:59 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
