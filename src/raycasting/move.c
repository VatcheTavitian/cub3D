/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:18:20 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/08 17:26:58 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_info *info)
{
	info->olddirx = info->dirx;
	info->dirx = info->dirx * cos(-info->rt_speed) - info->diry * \
		sin(-info->rt_speed);
	info->diry = info->olddirx * sin(-info->rt_speed) + info->diry * \
		cos(-info->rt_speed);
	info->oldplanex = info->planex;
	info->planex = info->planex * cos(-info->rt_speed) - info->planey * \
		sin(-info->rt_speed);
	info->planey = info->oldplanex * sin(-info->rt_speed) + info->planey * \
		cos(-info->rt_speed);
	raycasting(info);
}

void	rotate_left(t_info *info)
{
	info->olddirx = info->dirx;
	info->dirx = info->dirx * cos(info->rt_speed) - info->diry * \
		sin(info->rt_speed);
	info->diry = info->olddirx * sin(info->rt_speed) + info->diry * \
		cos(info->rt_speed);
	info->oldplanex = info->planex;
	info->planex = info->planex * cos(info->rt_speed) - info->planey * \
		sin(info->rt_speed);
	info->planey = info->oldplanex * sin(info->rt_speed) + info->planey * \
		cos(info->rt_speed);
	raycasting(info);
}

void	forward_backwards(t_info *info, char direction)
{
	if (direction == 'f')
	{
		if (info->map[(int)(info->pposx + info->dirx * \
		info->mv_speed)][(int)info->pposy] != '1')
		info->pposx += info->dirx * info->mv_speed;
		if (info->map[(int)info->pposx][(int)(info->pposy + \
		info->diry * info->mv_speed)] != '1')
		info->pposy += info->diry * info->mv_speed;
	}
	else if (direction == 'b')
	{
		if (info->map[(int)(info->pposx - info->dirx * \
			info->mv_speed)][(int)info->pposy] != '1')
			info->pposx -= info->dirx * info->mv_speed;
		if (info->map[(int)info->pposx][(int)(info->pposy - \
			info->diry * info->mv_speed)] != '1')
			info->pposy -= info->diry * info->mv_speed;
	}
}

void	left_right(t_info *info, char direction)
{
	if (direction == 'l')
	{
		if (info->map[(int)(info->pposx - info->diry * \
			info->mv_speed)][(int)info->pposy] != '1')
			info->pposx -= info->diry * info->mv_speed;
		if (info->map[(int)info->pposx][(int)(info->pposy + \
			info->dirx * info->mv_speed)] != '1')
			info->pposy += info->dirx * info->mv_speed;
	}
	else if (direction == 'r')
	{
		if (info->map[(int)(info->pposx + info->diry * \
			info->mv_speed)][(int)info->pposy] != '1')
			info->pposx += info->diry * info->mv_speed;
		if (info->map[(int)info->pposx][(int)(info->pposy - \
			info->dirx * info->mv_speed)] != '1')
			info->pposy -= info->dirx * info->mv_speed;
	}
}

int	move(int key, t_info *info)
{
	if (key == 126 || key == 13)
		forward_backwards(info, 'f');
	if (key == 125 || key == 1)
		forward_backwards(info, 'b');
	if (key == 2)
		left_right(info, 'r');
	if (key == 0)
		left_right(info, 'l');
	if (key == 124)
		rotate_right(info);
	if (key == 123)
		rotate_left(info);
	raycasting(info);
	return (0);
}
