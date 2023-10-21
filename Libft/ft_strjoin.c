/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:05:18 by vtavitia          #+#    #+#             */
/*   Updated: 2023/01/21 13:22:09 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		k;

	join = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	k = i;
	i = 0;
	while (s2[i])
	{
		join[k] = s2[i];
		i++;
		k++;
	}
	join[k] = '\0';
	return (join);
}
