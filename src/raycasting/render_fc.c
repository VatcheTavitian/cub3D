/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:07:29 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/08 17:39:00 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	convert_colours(t_info *info)
{
	info->ccol = (info->c1 << 16) | (info->c2 << 8) | info->c3;
	info->fcol = (info->f1 << 16) | (info->f2 << 8) | info->f3;
}

static void	draw_fc(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < info->sh / 2)
	{
		x = 0;
		while (x < info->sw)
			info->image->addr[y * info->sw + x++] = info->ccol;
		y++;
	}
	y = info->sh / 2;
	while (y < info->sh)
	{
		x = 0;
		while (x < info->sw)
			info->image->addr[y * info->sw + x++] = info->fcol;
		y++;
	}
}

void	render_fc(t_info *info)
{
	convert_colours(info);
	draw_fc(info);
}
