/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getident.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:30:16 by irifarac          #+#    #+#             */
/*   Updated: 2024/05/15 10:46:35 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	ft_list(char **tmp, int ret)
{
	if (**tmp == 0)
		return (0);
	else if (**tmp == 'A')
	{
		*tmp = *tmp + 1;
		return (ret);
	}
	else if (**tmp == 'C')
	{
		*tmp = *tmp + 1;
		return (ret);
	}
	else if (**tmp == 'L')
	{
		*tmp = *tmp + 1;
		return (ret);
	}
	return (0);
}

int	ft_getident(char **str, char *estr, char **ftoken, char **eftoken)
{
	char	*tmp;
	int		ret;

	tmp = *str;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	if (ftoken)
		*ftoken = tmp;
	ret = *tmp;
	if (*tmp == 'A' || *tmp == 'C' || *tmp == 'L')
		ret = ft_list(&tmp, ret);
	else
	{
		ret = 0;
		while (tmp < estr && !ft_strchr("ACL", *tmp))
			tmp++;
		printf("no ambient case\n");
	}
	while (tmp < estr && !ft_strchr("ACL", *tmp))
		tmp++;
	if (eftoken)
		*eftoken = tmp;
	*str = tmp;
	return (ret);
}
