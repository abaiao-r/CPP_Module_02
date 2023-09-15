/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:34:49 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/09/15 18:10:37 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include <cstdlib>

/* colours */
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

class Point
{
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point(void);
        Point(const Point &src);
        Point(const float x, const float y);
        ~Point(void);

        Point &operator=(const Point &src);

        Fixed getX(void) const;
        Fixed getY(void) const;
};

#endif
