/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:43:10 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/08 17:01:36 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_lines(int tmp)
{
	int		lines;
	char	buffer;
	int		txt;

	lines = 0;
	buffer = '\0';
	txt = 1;
	while (txt)
	{
		if (buffer == '\n' || buffer == '\0')
			lines++;
		txt = read(tmp, &buffer, 1);
	}
	return (lines);
}

int	check_map_content(t_info *info)
{
	int		fd;
	int		lines;
	char	buffer;

	fd = open(info->mpath, O_RDONLY);
	if (read(fd, &buffer, 1) == 0)
		return (1);
	fd = open(info->mpath, O_RDONLY);
	lines = count_lines(fd);
	info->lines = lines;
	if (check_each_line(lines, info))
		return (1);
	return (0);
}
