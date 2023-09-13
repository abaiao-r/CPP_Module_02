/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:20:37 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/09/13 19:25:44 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;    
    public:
        Fixed(void);                        // default constructor (void)
        Fixed(const int value);             // constructor with int
        Fixed(const float value);           // constructor with float
        Fixed(const Fixed &src);            // copy constructor of the class
        Fixed &operator=(const Fixed &src); // copy assignment operator
        ~Fixed(void);                       // destructor

        int getRawBits(void) const;
        void setRawBits(int const raw);
        int toInt(void) const;
        float toFloat(void) const;

        // Overload comparison operators
        bool operator>(const Fixed &src) const;
        bool operator<(const Fixed &src) const;
        bool operator>=(const Fixed &src) const;
        bool operator<=(const Fixed &src) const;
        bool operator==(const Fixed &src) const;
        bool operator!=(const Fixed &src) const;

        // Overload arithmetic operators
        Fixed operator+(const Fixed &src) const;
        Fixed operator-(const Fixed &src) const;
        Fixed operator*(const Fixed &src) const;
        Fixed operator/(const Fixed &src) const;

        // Overload increment and decrement operators
        Fixed &operator++(void); // prefix increment
        Fixed operator++(int);   // postfix increment
        Fixed &operator--(void); // prefix decrement
        Fixed operator--(int);   // postfix decrement

        // Overload min and max functions
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};

// Overload operator <<
std::ostream &operator<<(std::ostream &out, const Fixed &src);

#endif