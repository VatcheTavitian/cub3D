/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:01:58 by vtavitia          #+#    #+#             */
/*   Updated: 2023/01/29 16:29:11 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*ptr;
	size_t				i;
	unsigned char		l;

	i = 0;
	ptr = (unsigned char *)s;
	l = (unsigned char)c;
	while (ptr && i < n)
	{
		if (*ptr == l)
		{
			return (ptr);
		}
		ptr++;
		i++;
	}
	return (NULL);
}
