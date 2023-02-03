/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:14:52 by msoler-e          #+#    #+#             */
/*   Updated: 2023/02/03 12:12:16 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_ambient *s_lst( t_ambient *ambsearch, int type)
{
	t_light		*light;
	t_alight	*alight;
	t_cam		*cam;
	int i;

	i=0;
	while ( ambsearch && i++ < 4)
	{
		if (ambsearch->type == 0)
		{
			if (ambsearch->type == type)
				return (ambsearch);
			alight = (t_alight *)ambsearch;
			ambsearch = alight->amb;
		}
		else if (ambsearch->type == 1)
		{
			if (ambsearch->type == type)
				return (ambsearch);
			cam = (t_cam *)ambsearch;
			ambsearch = cam->amb;
		}
		else if (ambsearch->type == 2)
		{
			if (ambsearch->type == type)
				return (ambsearch);
			light = (t_light *)ambsearch;
			ambsearch = light->amb;
		}
		else
			return(0);
	}
	return (0);
}
