/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_text_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:04:07 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/08 17:10:26 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_text_file_syntax(char *name)
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
	if (!ft_strcmp((&(name[i])), "xpm"))
		return (0);
	else
		return (1);
}

int	check_text_path_exists(char *path)
{
	int	fd;

	if (check_text_file_syntax(path))
		return (perr("Please launch textures with only .xpm file\n"));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perr("Texture path does not exist: "), perr(path), perr("\n"));
	return (0);
}
