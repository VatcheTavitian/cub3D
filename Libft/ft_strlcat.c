/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:54:54 by vtavitia          #+#    #+#             */
/*   Updated: 2023/01/21 10:16:26 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	length(const char *string)
{
	unsigned int	counter;

	counter = 0;
	while (string[counter])
	{
		counter++;
	}
	return (counter);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	srci;
	unsigned int	rvalue;

	i = 0;
	srci = 0;
	rvalue = length(src) + length(dst);
	if (dstsize < 1)
		return (length(src) + dstsize);
	while (dst[i])
	{
		i++;
	}
	while (i < dstsize - 1 && src[srci])
	{
		dst[i] = src[srci];
		i++;
		srci++;
	}
	dst[i] = '\0';
	if (dstsize < length(dst))
		return (length(src) + dstsize);
	else
		return (rvalue);
}
