/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:20:37 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/09/13 18:59:46 by abaiao-r         ###   ########.fr       */
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
};

// Overload operator <<
std::ostream &operator<<(std::ostream &out, const Fixed &src);

#endif