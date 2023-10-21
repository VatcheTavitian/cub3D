/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:43:46 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/08 17:21:14 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	if (array[i])
		free(array[i]);
}

int	count_dots(char *name)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (name[i])
	{
		if (name[i] == '.')
			count++;
		i++;
	}
	return (count);
}

static int	check_file_syntax(char *name)
{
	int	i;
	int	dots;

	i = 0;
	dots = count_dots(name);
	if (!dots)
		return (1);
	while (name[i])
	{
		if (name[i] == '.' && dots >= 2)
		{
			i++;
			dots--;
		}
		if (name[i] == '.' && dots == 1)
			break ;
		i++;
	}
	i++;
	if (!ft_strcmp((&(name[i])), "cub"))
		return (0);
	else
		return (1);
}

static int	check_path_exists(char **argv, int *fd, t_info *info)
{
	if (check_file_syntax(argv[1]))
		exit (perr("Please launch with only .cub file\n"));
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
		exit(perr("Map path does not exist\n"));
	info->filefd = *fd;
	info->mpath = ft_strdup(argv[1]);
	return (0);
}

int	validate_map_file(int argc, char **argv, t_info *info)
{
	int	fd;

	if (argc != 2)
		return (perr("Please launch program with valid map path\n"));
	if (check_path_exists(argv, &fd, info))
		return (1);
	if (check_map_content(info))
		return (perr("Error parsing map: Check content is valid\n"));
	return (0);
}
