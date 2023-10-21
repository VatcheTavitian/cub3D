/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_directions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:01:13 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/08 17:40:17 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_dir_vals_px_zero(t_info *info, int dx, int dy, double py)
{
	info->dirx = dx;
	info->diry = dy;
	info->planex = 0;
	info->planey = py;
}

static void	set_dir_vals_py_zero(t_info *info, int dx, int dy, double px)
{
	info->dirx = dx;
	info->diry = dy;
	info->planex = px;
	info->planey = 0;
}

void	set_directions(t_info *info)
{
	char	d;

	d = info->dir;
	if (d == 'N')
		set_dir_vals_px_zero(info, -1, 0, 0.66);
	else if (d == 'S')
		set_dir_vals_px_zero(info, 1, 0, -0.66);
	else if (d == 'W')
		set_dir_vals_py_zero(info, 0, -1, -0.66);
	else if (d == 'E')
		set_dir_vals_py_zero(info, 0, 1, 0.66);
}
