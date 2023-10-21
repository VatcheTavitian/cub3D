/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatche <vatche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:49:04 by vtavitia          #+#    #+#             */
/*   Updated: 2023/01/29 21:44:45 by vatche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (start > (unsigned int)ft_strlen(s))
	{
		sub = malloc(sizeof(char) * 1);
		sub[0] = '\0';
		return (sub);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub = malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < len && len != 0)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
