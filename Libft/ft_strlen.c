/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:55:53 by vtavitia          #+#    #+#             */
/*   Updated: 2023/01/29 14:34:04 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int		i;
	char	*str1;

	if (!str)
		return (0);
	str1 = (char *)str;
	i = 0;
	while (str1[i] != '\0')
	{
		i++;
	}
	return (i);
}
