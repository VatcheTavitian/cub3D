/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:13:45 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/18 15:58:13 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	delete_content(t_info *info)
{
	int	i;

	i = 0;
	while (info->content[i])
	{
		free(info->content[i]);
		i++;
	}
	free(info->content);
	info->content = NULL;
}

int	arrsize(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i - 1);
}

void	assign_dir(t_info *info)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (info->map[i])
	{
		while (info->map[i][j])
		{
			c = info->map[i][j];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				info->dir = c;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	check_below(t_info *info, int i)
{
	while (info->content[i + 1])
	{
		if (!one_or_space(info->content[i + 1]) && \
		*(info->content[i + 1]) != '\0' && !just_ws(info->content[i + 1]))
			return (1);
		else
			i++;
	}
	return (0);
}

int	check_below_map(t_info *info, int i)
{
	while (info->map[i] && info->map[i + 1])
	{
		if (info->map[i + 1])
		{
			if (!just_ws(info->map[i + 1]))
				return (1);
		}
		i++;
	}
	return (0);
}
