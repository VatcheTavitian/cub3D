/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:11:52 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/08 17:27:12 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_wall_hit(t_info *info)
{
	while (info->hit == 0)
	{
		if (info->x_side_dist < info->y_side_dist)
		{
			info->x_side_dist += info->delta_x;
			info->mapx += info->xstep;
			info->side = 0;
		}
		else
		{
			info->y_side_dist += info->delta_y;
			info->mapy += info->ystep;
			info->side = 1;
		}
		if (info->map[info->mapx][info->mapy] == '1')
			info->hit = 1;
	}
}

void	find_ray_intersections(t_info *info)
{
	if (info->raydirection_x < 0)
	{
		info->xstep = -1;
		info->x_side_dist = (info->pposx - info->mapx) * info->delta_x;
	}
	else
	{
		info->xstep = 1;
		info->x_side_dist = (info->mapx + 1.0 - info->pposx) * info->delta_x;
	}
	if (info->raydirection_y < 0)
	{
		info->ystep = -1;
		info->y_side_dist = (info->pposy - info->mapy) * info->delta_y;
	}
	else
	{
		info->ystep = 1;
		info->y_side_dist = (info->mapy + 1.0 - info->pposy) * info->delta_y;
	}
}

void	set_params(t_info *info, int x)
{
	info->x_cam = 2 * x / (double)info->sw - 1;
	info->raydirection_x = info->dirx + info->planex * info->x_cam;
	info->raydirection_y = info->diry + info->planey * info->x_cam;
	info->mapx = (int)info->pposx;
	info->mapy = (int)info->pposy;
	if (info->raydirection_x == 0)
		info->delta_x = 1e30;
	else
		info->delta_x = fabs(1 / info->raydirection_x);
	if (info->raydirection_y == 0)
		info->delta_y = 1e30;
	else
		info->delta_y = fabs(1 / info->raydirection_y);
	info->hit = 0;
}

void	set_params_wall_render(t_info *info)
{
	if (info->side == 0)
		info->perpwalldist = (info->x_side_dist - info->delta_x);
	else
		info->perpwalldist = (info->y_side_dist - info->delta_y);
	info->lineheight = (int)(info->sh / info->perpwalldist);
	info->drawstart = -info->lineheight / 2 + info->sh / 2;
	if (info->drawstart < 0)
		info->drawstart = 0;
	info->drawend = info->lineheight / 2 + info->sh / 2;
	if (info->drawend >= info->sh)
		info->drawend = info->sh - 1;
	if (info->side == 1)
		info->color = info->color / 2;
	if (info->side == 0)
		info->wallx = info->pposy + info->perpwalldist * info->raydirection_y;
	else
		info->wallx = info->pposx + info->perpwalldist * info->raydirection_x;
	info->wallx -= floor(info->wallx);
}
