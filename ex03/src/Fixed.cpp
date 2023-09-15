/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:20:19 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/09/15 15:23:38 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/* Default constructor*/
Fixed::Fixed(void)
{
    //std::cout << "Default constructor called" << std::endl;
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
    //std::cout << "Int constructor called" << std::endl;
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
    //std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(value * (1 << this->fractionalBits));
}

/* Copy constructor of the class
** The copy constructor does a memberwise copy of the object, in this case
** it copies the fixedPointValue attribute.
*/
Fixed::Fixed(const Fixed &src)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

/* Copy assignment operator
** The copy assignment operator does a memberwise copy of the object, in this
** case it copies the fixedPointValue attribute.
*/
Fixed &Fixed::operator=(const Fixed &src)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    this->fixedPointValue = src.getRawBits();
    return (*this);
}

/* Destructor */
Fixed::~Fixed(void)
{
   /*  std::cout << "Destructor called" << std::endl; */
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
    //std::cout << "setRawBits member function called" << std::endl;
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
*/
std::ostream &operator<<(std::ostream &out, const Fixed &src)
{
    out << src.toFloat();
    return (out);
}

/* Overload operator <
** overload operator are used to redefine the way operators work. in this case
** we are redefining the way the operator < works. we are telling the compiler
** that when we use the operator < with two fixed point values, we want it to
** compare the fixedPointValue attribute of the two objects.
** this funtion returns true if the fixed point value on the left is smaller
*/
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

/* Overload operator <
** Returns the fixed point value that is the smallest of the two fixed point
** values that are passed as parameters.
*/
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}

/* Overload operator >
** Returns the fixed point value that is the largest of the two fixed point
** values that are passed as parameters.
*/
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

/* Overload operator >
** Returns the fixed point value that is the largest of the two fixed point
** values that are passed as parameters.
*/
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}

/* Overload operator ==
** Returns true if the two fixed point values are equal.
*/
bool Fixed::operator==(const Fixed &src) const
{
    return (this->fixedPointValue == src.getRawBits());
}

/* Overload operator !=
** Returns true if the two fixed point values are not equal.
*/
bool Fixed::operator!=(const Fixed &src) const
{
    return (this->fixedPointValue != src.getRawBits());
}

/* Overload operator <
** Returns true if the fixed point value on the left is smaller than the
** fixed point value on the right.
*/
bool Fixed::operator<(const Fixed &src) const
{
    return (this->fixedPointValue < src.getRawBits());
}

/* Overload operator >
** Returns true if the fixed point value on the left is larger than the
** fixed point value on the right.
*/
bool Fixed::operator>(const Fixed &src) const
{
    return (this->fixedPointValue > src.getRawBits());
}

/* Overload operator <=
** Returns true if the fixed point value on the left is smaller or equal than
** the fixed point value on the right.
*/
bool Fixed::operator<=(const Fixed &src) const
{
    return (this->fixedPointValue <= src.getRawBits());
}

/* Overload operator >=
** Returns true if the fixed point value on the left is larger or equal than
** the fixed point value on the right.
*/
bool Fixed::operator>=(const Fixed &src) const
{
    return (this->fixedPointValue >= src.getRawBits());
}

/* Overload operator +
** Returns the sum of the two fixed point values.
*/
Fixed Fixed::operator+(const Fixed &src) const
{
    Fixed result;

    result.setRawBits(this->getRawBits() + src.getRawBits());
    return (result);
}

/* Overload operator -
** Returns the difference of the two fixed point values.
*/
Fixed Fixed::operator-(const Fixed &src) const
{
    Fixed result;

    result.setRawBits(this->getRawBits() - src.getRawBits());
    return (result);
}

/* Overload operator * 
** Returns the product of the two fixed point values.
*/
Fixed Fixed::operator*(const Fixed &src) const
{
    Fixed result;

    result.setRawBits(((int64_t)this->getRawBits() * (int64_t)src.getRawBits()) 
        >> this->fractionalBits);
    return (result);
}

/* Overload operator /
** Returns the quotient of the two fixed point values.
*/
Fixed Fixed::operator/(const Fixed &src) const
{
    if (src.getRawBits() != 0)
    {
        Fixed result;

        result.setRawBits(((int64_t)this->getRawBits() << this->fractionalBits)
            / (int64_t)src.getRawBits());
        return (result);
    }
    else
    {
        std::cout << "Error: Division by zero" << std::endl;
        return (Fixed(0));
    }
}

/* Overload operator ++
** Returns the fixed point value after incrementing it by 1.
*/
Fixed &Fixed::operator++(void)
{
    this->fixedPointValue++;
    return (*this);
}

/* Overload operator ++
** Returns the fixed point value before incrementing it by 1.
*/
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return (tmp);
}

/* Overload operator -- 
** Returns the fixed point value after decrementing it by 1.
*/
Fixed &Fixed::operator--(void)
{
    this->fixedPointValue--;
    return (*this);
}

/* Overload operator --
** Returns the fixed point value before decrementing it by 1.
*/
Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return (tmp);
}
