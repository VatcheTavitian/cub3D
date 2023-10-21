/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_each_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:01:21 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/17 15:13:29 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_checks(char **checks)
{
	checks[0] = ft_strdup("NO");
	checks[1] = ft_strdup("SO");
	checks[2] = ft_strdup("WE");
	checks[3] = ft_strdup("EA");
	checks[4] = ft_strdup("F");
	checks[5] = ft_strdup("C");
	checks[6] = NULL;
}

int	id_in_list(char *id)
{
	char	*checks[7];
	int		i;

	i = 0;
	init_checks(checks);
	while (checks[i])
	{
		if (!ft_strcmp(checks[i], id))
		{
			free_all(checks);
			return (1);
		}
		i++;
	}
	free_all(checks);
	return (0);
}

void	check_all_allocated(t_info *i)
{
	if (!i->no || !i->so || !i->we || !i->ea || !i->c || !i->f)
	{
		perr("Some parameters are missing/incorrectly configured\n");
		exit(1);
	}
}

int	check_each_line(int lines, t_info *info)
{
	char	**content;
	int		fd;
	int		chars;
	int		move;

	content = (char **)malloc(sizeof(char **) * (lines + 1));
	fd = open(info->mpath, O_RDONLY);
	read_to_array(fd, move, content, info);
	assign_textures(info);
	check_all_allocated(info);
	process_colors(info);
	parse_map(info);
	return (0);
}
