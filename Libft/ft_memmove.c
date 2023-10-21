/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:27:47 by vtavitia          #+#    #+#             */
/*   Updated: 2023/01/20 14:36:41 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	char			*d;
	const char		*s;	

	d = dst;
	s = src;
	i = 0;
	if (dst < src)
	{
		while (d && i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	if (dst > src)
	{
		i = len;
		while (d && i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (d);
}
