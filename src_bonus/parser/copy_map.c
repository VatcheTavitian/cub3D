/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 08:59:05 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/18 15:57:19 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	trim_map_helper(t_info *info, int i)
{
	int		t;
	int		size;
	char	**map;

	map = info->map;
	t = i;
	size = arrsize(map);
	if (just_ws(map[t]))
	{
		free(map[t]);
		info->map[t] = NULL;
		while (t <= size)
		{
			free(info->map[t]);
			t++;
		}
	}
}

void	check_gaps_in_map(t_info *info)
{
	int		i;
	char	**map;

	map = info->map;
	i = 0;
	while (map[i] && just_ws(map[i]))
		i++;
	while (map[i] && !just_ws(map[i]))
		i++;
	if (i < arrsize(map) && check_below_map(info, i))
		exit(perr("Error: Gap in map\n"));
}

static void	trim_map(t_info *info)
{
	char	**map;
	int		i;

	i = 0;
	map = info->map;
	check_gaps_in_map(info);
	while (map[i] && just_ws(map[i]))
	{
		info->map = &(map[i + 1]);
		free(map[i]);
		i++;
	}
	map = info->map;
	i = 0;
	while (map[i] && !just_ws(map[i]))
		i++;
	if (map[i] && just_ws(map[i]))
		trim_map_helper(info, i);
}

static void	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	if (!(src || dst))
		return ;
	else
	{
		while ((src)[i])
		{
			(dst)[i] = (src)[i];
			i++;
		}
		(dst)[i] = '\0';
	}
}

void	copy_map(t_info *info, int st)
{
	int	i;

	i = 0;
	info->map = (char **)malloc(sizeof(char *) * ((info->lines - st) + 1));
	if (!info->map)
		exit(perr("Error copying map\n"));
	while (info->content[st] != NULL)
	{
		info->map[i] = \
			(char *)malloc(sizeof(char) * (ft_strlen(info->content[st]) + 1));
		if (!info->map[i])
			exit(perr("Error mallocing map line\n"));
		ft_strcpy(info->map[i], info->content[st]);
		st++;
		i++;
	}
	info->map[i] = NULL;
	trim_map(info);
	if (!info->map)
		exit(perr("No map found\n"));
	set_map_lines(info);
	if (!info->map_lines)
		exit(perr("No map found!\n"));
}
