/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:59:41 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/09/15 18:35:23 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsp.hpp"

/* ft_abs function
** 1. If the area is negative, multiply it by -1 to make it positive.
** If the area is positive, leave it as is.
*/
static Fixed ft_abs(Fixed area)
{
    return(area < 0 ? area * -1 : area);
}

/* ft_area function
** 1. Calculate the area using the formula:
**    area = (Ax(By - Cy) + Bx(Cy - Ay) + Cx(Ay - By)) / 2
** this formula works because the area of a triangle is half the area of a
** parallelogram of the same base and height.
*/
static Fixed ft_area(Point const a, Point const b, Point const c)
{   
    return ((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) 
        + c.getX() * (a.getY() - b.getY())) / 2);
}

/* bsp function
** 1. Calculate the area of the triangle ABC
** 2. Calculate the area of the triangle PBC
** 3. Calculate the area of the triangle PAC
** 4. Calculate the area of the triangle PAB
** 5. If the sum of the three areas of the triangles PBC, PAC and PAB is equal 
** to the area of the triangle ABC, the point P is inside the triangle ABC.
** 6. If the sum of the three areas of the triangles PBC, PAC and PAB is greater
** than the area of the triangle ABC, the point P is outside the triangle ABC.
** 7. If the sum of the three areas of the triangles PBC, PAC and PAB is less 
** than the area of the triangle ABC, the point P is outside the triangle ABC.
*/
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC;
    Fixed areaPBC;
    Fixed areaPAC;
    Fixed areaPAB;

    areaABC = ft_abs(ft_area(a, b, c));
    areaPBC = ft_abs(ft_area(point, b, c));
    areaPAC = ft_abs(ft_area(a, point, c));
    areaPAB = ft_abs(ft_area(a, b, point));

    std::cout << "areaABC: " << areaABC << std::endl;
    std::cout << "areaPBC: " << areaPBC << std::endl;
    std::cout << "areaPAC: " << areaPAC << std::endl;
    std::cout << "areaPAB: " << areaPAB << std::endl;
    std::cout << "areaPBC + areaPAC + areaPAB: " << areaPBC + areaPAC + areaPAB 
        << std::endl;
    
    if (areaABC == 0 || areaPBC == 0 || areaPAC == 0 || areaPAB == 0)
        return (false);
    
    if (areaABC == (areaPBC + areaPAC + areaPAB))
        return (true);
    else
        return (false);
}
