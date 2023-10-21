/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:25:28 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/16 12:54:18 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_all_ones(char *s)
{
	int	i;

	i = 0;
	if (!ft_strlen(s))
		exit(perr("Invalid map config\n"));
	while (s[i])
	{
		if (s[i] != '1' && s[i] != ' ' && s[i] != '\t')
			exit(perr("Invalid characters on outer edges of map\n"));
		i++;
	}
}

static void	check_total_pos_helper(char **map, int n, int s, int w)
{
	int	e;
	int	i;
	int	j;

	e = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				n++;
			else if (map[i][j] == 'S')
				s++;
			else if (map[i][j] == 'W')
				w++;
			else if (map[i][j] == 'E')
				e++;
			j++;
		}
		j = 0;
		i++;
	}
	validate_result(n, s, w, e);
}

static void	check_total_pos(char **map)
{
	int	n;
	int	s;
	int	w;

	n = 0;
	s = 0;
	w = 0;
	check_total_pos_helper(map, n, s, w);
}

static void	check_illegal_chars(char **map)
{
	int		i;
	int		j;
	char	*allowed;

	i = 0;
	j = 0;
	allowed = " 01NSWE\t";
	while (map[i])
	{
		while (map[i][j])
		{
			if (!ft_strchr(allowed, map[i][j]))
				exit(perr("Illegal characters in map\n"));
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_map_chars(t_info *info)
{
	int		i;
	char	**map;

	i = 0;
	map = info->map;
	check_all_ones(map[i]);
	check_all_ones(map[info->map_lines - 1]);
	check_total_pos(map);
	check_illegal_chars(map);
}
