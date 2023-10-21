/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatche <vatche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:51:45 by vtavitia          #+#    #+#             */
/*   Updated: 2023/01/29 20:29:16 by vatche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*arr;
	size_t			i;

	i = 0;
	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	arr = malloc(count * size);
	if (!arr)
		return (NULL);
	while (i < count * size)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}
