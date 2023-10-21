/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:41:44 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/19 13:55:47 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	parsestr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] <= 32 && str[i] != '\e')
	{
		if (str[i] == '\\')
			i++;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	rvalue;
	int	sign;
	int	i;

	if (ft_strlen(str) == 0)
		return (0);
	rvalue = 0;
	sign = 1;
	i = parsestr(str);
	if (str[i] == '-' && str[i + 1] != '+')
	{
		sign *= -1;
		i++;
	}
	if (str[i] == '+')
	{
		i++;
	}
	while (((str[i] >= 48 && str[i] <= 57)))
	{
		rvalue = rvalue * 10 + str[i] - '0';
		i++;
	}
	return (rvalue * sign);
}
