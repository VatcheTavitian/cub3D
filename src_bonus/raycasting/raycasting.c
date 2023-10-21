/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:34:13 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/18 14:13:06 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculating_textured_rendering_wall(t_info *info, int x)
{
	int	y;

	info->x_texture = (int)(info->wallx * (double)info->wall_texture->iw);
	if ((info->side == 0 && info->raydirection_x > 0) \
		|| (info->side == 1 && info->raydirection_y < 0))
		info->x_texture = info->wall_texture->iw - info->x_texture - 1;
	info->texture_height = (int)(info->sh / info->perpwalldist);
	info->drawstart = -info->texture_height / 2 + info->sh / 2;
	if (info->drawstart < 0)
		info->drawstart = 0;
	info->drawend = info->texture_height / 2 + info->sh / 2;
	if (info->drawend >= info->sh)
		info->drawend = info->sh - 1;
	y = info->drawstart;
	while (y < info->drawend)
	{
		info->y_texture = (int)(((y - info->sh / 2 + info->texture_height / 2) \
			* info->wall_texture->ih) / info->texture_height);
		info->color = info->wall_texture->addr[info->y_texture \
			* info->wall_texture->iw + info->x_texture];
		info->image->addr[y * info->sw + x] = info->color;
		y++;
	}
}

void	wall_side(t_info *info)
{
	if (info->side == 0)
	{
		if (info->raydirection_x > 0)
			info->wall_texture = info->e_img;
		else
			info->wall_texture = info->w_img;
	}
	else
	{
		if (info->raydirection_y > 0)
			info->wall_texture = info->n_img;
		else
			info->wall_texture = info->s_img;
	}
}

void	raycast_walls(t_info *info)
{
	int	x;

	x = 0;
	while (x < info->sw)
	{
		set_params(info, x);
		find_ray_intersections(info);
		check_wall_hit(info);
		set_params_wall_render(info);
		wall_side(info);
		calculating_textured_rendering_wall(info, x);
		x++;
	}
}

static void	put_animation(t_info *info, void *path)
{
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, path, \
		info->sw * 0.55, info->sh * 0.6);
}

void	raycasting(t_info *info)
{
	info->image = malloc(sizeof(t_img));
	info->image->img = mlx_new_image(info->mlx_ptr, info->sw, info->sh);
	info->image->addr = (int *)mlx_get_data_addr(info->image->img, \
		&info->image->bpp, &info->image->ll, &info->image->endian);
	render_fc(info);
	raycast_walls(info);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, \
		info->image->img, 0, 0);
	if (info->lineheight < 1000)
		put_animation(info, info->hands_img->img);
	else if (info->lineheight > 1000)
		put_animation(info, info->gun_wall_img->img);
	mlx_destroy_image(info->mlx_ptr, info->image->img);
	free(info->image);
}
