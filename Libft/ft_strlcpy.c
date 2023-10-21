/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:55:24 by vtavitia          #+#    #+#             */
/*   Updated: 2023/01/29 16:59:20 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;

	index = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[index] && index < dstsize - 1)
	{
		dst[index] = src[index];
		index++;
	}
	if (index < dstsize)
		dst[index] = '\0';
	return ((size_t)ft_strlen(src));
}
