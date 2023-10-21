/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:45:18 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/17 15:13:44 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_dup_assign(char **key, char *path, int x)
{
	if (!(*key))
		*key = ft_strdup(path);
	else
		return (perr("Duplicate texture ID's found!\n"), 1);
	if (x && check_text_path_exists(path))
		return (1);
	return (0);
}

void	assign_path(t_info *info, char *id, char *path)
{
	int	mark;

	mark = 0;
	if (!ft_strcmp(id, "NO"))
		mark = check_dup_assign(&(info->no), path, 1);
	else if (!ft_strcmp(id, "SO"))
		mark = check_dup_assign(&(info->so), path, 1);
	else if (!ft_strcmp(id, "WE"))
		mark = check_dup_assign(&(info->we), path, 1);
	else if (!ft_strcmp(id, "EA"))
		mark = check_dup_assign(&(info->ea), path, 1);
	else if (!ft_strcmp(id, "C"))
		mark = check_dup_assign(&(info->c), path, 0);
	else if (!ft_strcmp(id, "F"))
		mark = check_dup_assign(&(info->f), path, 0);
	if (mark)
	{
		free(path);
		free(id);
		exit(1);
	}
}

void	check_illegal_config(char *id, char *path)
{
	if (!id_in_list(id) && !(id[0] == ' ' || id[0] == '1' || id[0] == '\t'))
	{
		free(id);
		free(path);
		exit(perr("Illegal file configuration: unknown parameters\n"));
	}
}

void	get_ident(char *line, char *id, char *path, t_info *info)
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
	if (id_in_list(id))
		assign_path(info, id, path);
	else
		check_illegal_config(id, path);
	free(id);
	free(path);
}

void	assign_textures(t_info *info)
{
	char	**t;
	int		i;
	char	*id;
	char	*path;

	t = info->content;
	i = 0;
	while (t[i])
	{
		get_ident(t[i], id, path, info);
		i++;
	}
}
