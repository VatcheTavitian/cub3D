/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:30:45 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/19 13:08:46 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_info(t_info *info)
{
	info->f1 = 0;
	info->f2 = 0;
	info->f3 = 0;
	info->c1 = 0;
	info->c2 = 0;
	info->c3 = 0;
	info->lines = 0;
	info->map_lines = 0;
	info->pposx = 0;
	info->pposy = 0;
	info->dirx = 0;
	info->diry = 0;
	info->planex = 0;
	info->planey = 0.66;
	info->dir = '\0';
	info->so = NULL;
	info->no = NULL;
	info->we = NULL;
	info->ea = NULL;
	info->c = NULL;
	info->f = NULL;
	info->sh = 600;
	info->sw = 800;
}

void	free_everything(t_info *info)
{
	free(info->no);
	free(info->so);
	free(info->we);
	free(info->ea);
	free(info->c);
	free(info->f);
	free(info->mpath);
	free_all(info->map);
	delete_content(info);
	free_all(info->content);
	free(info->content);
	free(info);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	initialize_info(info);
	if (validate_map_file(argc, argv, info))
	{
		return (1);
	}
	begin_game(info);
}
