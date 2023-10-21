/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:58:33 by vtavitia          #+#    #+#             */
/*   Updated: 2023/01/27 19:11:40 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;
	char	*s1;

	s1 = (char *)s;
	i = 0;
	last = NULL;
	while (s1[i])
	{
		if (s1[i] == (char)c)
			last = &s1[i];
		i++;
	}
	if (c == '\0')
		return (&s1[i]);
	return (last);
}
