/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:20:19 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/09/15 17:41:57 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/* Default constructor*/
Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->fixedPointValue = 0;
}

/* Constructor that takes a constant int as a parameter
** The constructor should turn that into a fixed point value that is stored
** in the fixedPointValue attribute.
** You should multiply the integer value by 2^fractionalBits.
** e.g. 10 * 2^8 = 2560
*/
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = value << this->fractionalBits;
}

/* Constructor that takes a constant float as a parameter
** The constructor should turn that into a fixed point value that is stored
** in the fixedPointValue attribute.
** You should multiply the float value by 2^fractionalBits.
** e.g. 42.42 * (1 * 2^8) = 10859.52 rounded to 10860
*/
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(value * (1 << this->fractionalBits));
}

/* Copy constructor of the class
** The copy constructor does a memberwise copy of the object, in this case
** it copies the fixedPointValue attribute.
*/
Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

/* Copy assignment operator
** The copy assignment operator does a memberwise copy of the object, in this
** case it copies the fixedPointValue attribute.
*/
Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixedPointValue = src.getRawBits();
    return (*this);
}

/* Destructor */
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

/* getRawBits member function
** Returns the raw value of the fixed point value.
*/
int Fixed::getRawBits(void) const
{
    return (this->fixedPointValue);
}

/* setRawBits member function
** Sets the raw value of the fixed point value.
*/
void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}

/*  toInt member function
**  Returns the integer value of the fixed point value by shifting all bits
**  to the right by the number of fractional bits.
*/
int Fixed::toInt(void) const
{
    return (this->fixedPointValue >> this->fractionalBits);
}

/*  toFloat member function
**  Returns the float value of the fixed point value by shifting all bits
**  to the right by the number of fractional bits.
** e.g. 2560 / (1 * 2^8) = 10
** e.g. 10860 / (1 * 2^8) = 42.4219
*/
float Fixed::toFloat(void) const
{
    return ((float)this->fixedPointValue / (float)(1 << this->fractionalBits));
}

/* Overload operator <<
** Displays the fixed point value as a float.
** It is used in the main function to display the result of the toInt() method.
*/
std::ostream &operator<<(std::ostream &out, const Fixed &src)
{
    out << src.toFloat();
    return (out);
}
