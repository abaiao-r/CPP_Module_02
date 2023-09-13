/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:10:23 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/09/13 13:44:29 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// Default constructor
Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->fixedPointValue = 0;
}

// Copy constructor
Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

// copy assignment operator
Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixedPointValue = src.getRawBits();
    return (*this);
}

// Destructor
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

// member functions

// getRawBits: returns the raw value of the fixed point value.
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPointValue);
}

// setRawBits: sets the raw value of the fixed point value.
void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}