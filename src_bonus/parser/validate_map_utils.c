/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:44:13 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/19 13:48:06 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_fields_helper(char *line, char *id, char *path, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return ;
	j = i;
	while (line[j] && line[j] != ' ')
		j++;
	id = ft_substr(line, i, j - i);
	i = j;
	while (line[i] && line[i] == ' ')
		i++;
	while (line[j])
		j++;
	path = ft_substr(line, i, j - i);
	if (!id_in_list(id))
	{
		exit(perr("Map file configuration incorrect!!!\n"));
	}
	free(id);
	free(path);
}

void	check_fields_before_map(t_info *info, int start)
{
	int		i;
	int		j;
	char	*id;
	char	*path;

	i = 0;
	j = 0;
	id = NULL;
	path = NULL;
	while (i < start)
	{
		check_fields_helper(info->content[i], id, path, info);
		i++;
	}
}

void	validate_result(int n, int s, int w, int e)
{
	if ((n + s + w + e) > 1)
		exit(perr("Too many start locations\n"));
	if ((n + s + w + e) == 0)
		exit(perr("Start location not set\n"));
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 - *s2 == 0)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	set_map_lines(t_info *info)
{
	int	i;

	i = 0;
	while (info->map[i])
		i++;
	info->map_lines = i;
	if (info->map_lines <= 2)
		exit(perr("Map size invalid!\n"));
}
