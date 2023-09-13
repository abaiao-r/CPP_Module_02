/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:10:05 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/09/13 14:15:55 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;
    
    public:
        // Default constructor
        Fixed(void);
        // Copy constructor
        Fixed(const Fixed &src);
        // copy assignment operator
        Fixed &operator=(const Fixed &src);
        // Destructor
        ~Fixed(void);

        // member functions
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif
