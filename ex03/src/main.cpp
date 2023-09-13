/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:20:02 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/09/13 21:06:45 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

int main(void)
{
    Point a(0, 0);
    Point b(1, 0);
    Point c(0, 1);
    Point point(2, 1.9);

    std::cout << "a: " << a.getX() << ", " << a.getY() << std::endl;
    std::cout << "b: " << b.getX() << ", " << b.getY() << std::endl;
    std::cout << "c: " << c.getX() << ", " << c.getY() << std::endl;
    std::cout << "point: " << point.getX() << ", " << point.getY() << std::endl;

    std::cout << "bsp(a, b, c, point): " << bsp(a, b, c, point) << std::endl;

    return (0);
}

