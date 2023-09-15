/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:20:02 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/09/15 18:36:39 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsp.hpp"

int main(void)
{
    size_t i;
    //triangle points
    Point a(0, 0);
    Point b(10, 5);
    Point c(0, 10);

    //point test
    Point testPoints[] =
    {
        Point(5, 5), // Inside the triangle
        Point(5, 15), // Outside the triangle
        Point(0, 0), // Outside the triangle
        Point(1.5, 5.6), // Inside the triangle
    };

    i = 0;
    while (i < sizeof(testPoints) / sizeof(testPoints[0]))
    {
        if (bsp(a, b, c, testPoints[i]) == true)
        {
            std::cout << "a: " << a.getX() << ", " << a.getY() << std::endl;
            std::cout << "b: " << b.getX() << ", " << b.getY() << std::endl;
            std::cout << "c: " << c.getX() << ", " << c.getY() << std::endl;
            std::cout << GREEN << "Point " << testPoints[i].getX() << ", " 
                << testPoints[i].getY() << " is inside the triangle: true." 
                << RESET << std::endl;
        }
        else
        {
            std::cout << "a: " << a.getX() << ", " << a.getY() << std::endl;
            std::cout << "b: " << b.getX() << ", " << b.getY() << std::endl;
            std::cout << "c: " << c.getX() << ", " << c.getY() << std::endl;
            std::cout << RED << "Point " << testPoints[i].getX() << ", " 
                << testPoints[i].getY() << " is inside the triangle: false." 
                << RESET << std::endl;
        }
        i++;
    }
    return (0);
}
