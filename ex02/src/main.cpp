/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:20:02 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/09/15 17:57:58 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/* int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;


return 0;
} */

/*  main to test ex02 */
int main(void)
{
    // Test constructors
    Fixed a;             // Default constructor
    Fixed b(10);         // Constructor with int
    Fixed c(42.42f);     // Constructor with float

    // Test copy constructor and assignment operator
    Fixed d(b);          // Copy constructor
    Fixed e = c;         // Assignment operator

    // Test comparison operators
    if (a < b)
    {
        std::cout << "a is less than b" << std::endl;
    }
    if (c >= d)
    {
        std::cout << "c is greater than or equal to d" << std::endl;
    }

    // Test arithmetic operators
    Fixed f = b + c;        // int(10) + float(42.42)
    Fixed g = d - e;        // int(10) - float(42.42)
    Fixed h = f * g;        // float (52.42) * float(-32.42)
    Fixed i = h / b;        // float (52.42 * 52.42) / int(10)

    // Test increment and decrement operators
    Fixed j = ++a;          // Pre-increment of a (int a = 0) 
    Fixed k = b++;          // Post-increment of b (int b = 10)

    // Test min and max functions
    Fixed minResult = Fixed::min(a, b); // 
    Fixed maxResult = Fixed::max(c, d);

    // Test equality operators
    if (a == b)
    {
        std::cout << "a is equal to b" << std::endl;
    }
    if (c != d)
    {
        std::cout << "c is not equal to d" << std::endl;
    }

    // Print out results
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "f: " << f << std::endl;
    std::cout << "g: " << g << std::endl;
    std::cout << "h: " << h << std::endl;
    std::cout << "i: " << i << std::endl;
    std::cout << "j: " << j << std::endl;
    std::cout << "k: " << k << std::endl;
    std::cout << "minResult: " << minResult << std::endl;
    std::cout << "maxResult: " << maxResult << std::endl;

    return (0);
}
