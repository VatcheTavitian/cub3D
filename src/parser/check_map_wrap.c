/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wrap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:09:08 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/17 14:33:53 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_loc(char pos, char player, t_info *info)
{
	if (pos != '1' && pos != '0' && pos != player)
	{
		perr("Map should be enclosed with walls!");
		exit(1);
	}
}

static void	check_enclosed_helper(t_info *info, int x, int y)
{
	if (ft_strlen(info->map[y - 1]) >= x)
		check_loc(info->map[y - 1][x], info->dir, info);
	else
	{
		perr("Map should be enclosed with walls");
		exit(1);
	}
	check_loc(info->map[y + 1][x], info->dir, info);
	check_loc(info->map[y][x - 1], info->dir, info);
	check_loc(info->map[y][x + 1], info->dir, info);
}

static void	check_enclosed(int x, int y, t_info *info)
{
	while (info->map[y])
	{
		x = 0;
		while (info->map[y][x])
		{
			if (info->map[y][x] == info->dir)
			{
				info->pposx = y + 0.5;
				info->pposy = x + 0.5;
				info->map[y][x] = '0';
			}
			if (info->map[y][x] == '0')
			{
				if (y == 0 || y == arrsize(info->map))
				{
					perr("Map should be enclosed with walls");
					exit(1);
				}
				check_enclosed_helper(info, x, y);
			}
			x++;
		}
		y++;
	}
}

static void	check_first_last(char **map, int i, int j)
{
	i = 1;
	while (map[i])
	{
		while (map[i][j])
		{
			while (map[i][j] && (map[i][j] == ' ' || map[i][j] == '\t'))
				j++;
			if (map[i][j] != '1')
				exit(perr("Error: Map not surrounded by walls\n"));
			while (map[i][j])
				j++;
			j--;
			if (map[i][j] == ' ' || map[i][j] == '\t')
			{
				while ((map[i][j] == ' ' || map[i][j] == '\t'))
					j--;
			}
			if (map[i][j] != '1')
				exit(perr("Error: Map not surrounded by walls\n"));
			else
				break ;
		}
		j = 0;
		i++;
	}
}

void	check_map_wrap(t_info *info)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = info->map;
	check_first_last(map, i, j);
	check_enclosed(0, 0, info);
}
