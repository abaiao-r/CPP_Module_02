/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:10:23 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/09/15 16:56:34 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/* Default constructor
 * The default constructor should initialize the raw bits member variable to 0.
 * This is the constructor that the compiler will use if no parameter is passed.
 * The default constructor should also output “Default constructor called”.
 */
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPointValue = 0;
}

/* Copy constructor
 * The copy constructor should initialize the raw bits member variable to the
 * value of the raw bits member variable of the object passed as parameter.
 * The copy constructor should also output “Copy constructor called”.
 * this constructor will be called when you create a new object and initialize
 * it with another existing object of the same type.
 */
Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/* Assignment operator overload
 * The assignment operator overload should do the same as the copy constructor.
 * The assignment operator overload should also output “Assignation operator
 * called”.
 * This operator will be called when you assign an object to another using the
 * = operator.
 */
Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPointValue = src.getRawBits();
	return (*this);
}

/* Destructor
 * The destructor should output “Destructor called”.
 */
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/* getRawBits: returns the raw value of the fixed point value.*/
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
}

/* setRawBits: sets the raw value of the fixed point value.*/
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}
