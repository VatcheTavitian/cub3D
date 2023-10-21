/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:35:34 by vtavitia          #+#    #+#             */
/*   Updated: 2023/01/20 15:29:08 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;
	int		size;

	size = ft_strlen((char *)s1) + 1;
	ptr = malloc(sizeof(char) * size);
	i = 0;
	while (s1[i] != '\0')
	{
		*(ptr + i) = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
