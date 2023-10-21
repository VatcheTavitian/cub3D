/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:52:28 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/18 15:55:26 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	one_or_space(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			while (s[i] == ' ' || s[i] == '\t')
				i++;
		}
		if (s[i] == '1')
			return (1);
		else
			return (0);
	}
	return (0);
}

int	just_ws(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (s[i] != ' ')
			return (0);
		else
			i++;
	}
	return (1);
}

int	perr(char *s)
{
	if (!(*s))
		return (1);
	while (*s)
		write(2, s++, 1);
	return (1);
}

int	skip_lines_to_map(t_info *info)
{
	int	i;

	i = 0;
	while (info->content[i])
	{
		if (info->content[i] && just_ws(info->content[i]))
			i++;
		else if (info->content[i] && !one_or_space(info->content[i]))
		{
			if (!check_below(info, i))
			{
				i++;
				break ;
			}
			else
				i++;
		}
		else
			i++;
	}
	return (i);
}

void	parse_map(t_info *info)
{
	int	start;

	start = skip_lines_to_map(info);
	if (!info->content[start])
		exit(perr("Map file configuration incorrect - check map format\n"));
	check_fields_before_map(info, start);
	copy_map(info, start);
	check_map_chars(info);
	assign_dir(info);
	check_map_wrap(info);
}
