/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scalar_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:06:46 by msoler-e          #+#    #+#             */
/*   Updated: 2023/02/15 12:48:20 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

double	ft_min_double(double x, double y)
{
	double	temp;

	temp = 0.0;
	if (y > x)
	{
		temp = x;
		x = y;
		y = temp;
	}
	return (fabs(x));

}
