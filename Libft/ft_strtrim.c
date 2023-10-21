/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:26:49 by vtavitia          #+#    #+#             */
/*   Updated: 2023/01/30 13:33:55 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copycontent(char **trim, char const *s1, int start, int end)
{
	int	j;

	j = 0;
	while (start <= end)
	{
		(*trim)[j] = s1[start];
		start++;
		j++;
	}
	(*trim)[j] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		len;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (end >= start && ft_strchr(set, s1[end]))
		end--;
	len = end - start + 1;
	trim = malloc(sizeof(char) * len + 1);
	if (!trim)
		return (NULL);
	ft_copycontent(&trim, s1, start, end);
	return (trim);
}
