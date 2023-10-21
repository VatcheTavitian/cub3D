/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:20:18 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/18 14:13:33 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	quit(int keycode, t_info *info)
{
	(void)info;
	(void)keycode;
	exit(EXIT_SUCCESS);
	return (0);
}

int	mv_mouse(int x, int y, t_info *info)
{
	mlx_mouse_hide();
	mlx_mouse_get_pos(info->win_ptr, &x, &y);
	if (x > info->sw / 2)
		move(124, info);
	else if (x < info->sw / 2)
		move(123, info);
	mlx_mouse_move(info->win_ptr, info->sw / 2, y / 2);
	return (0);
}

int	key_hooks(int key, t_info *info)
{
	if (key == 53)
		exit(1);
	if (key == 126 || key == 125 || key == 124 || key == 123 \
	|| key == 0 || key == 1 || key == 2 || key == 13)
		move(key, info);
	return (0);
}

int	switch_textures(void *param)
{
	t_info	*info;
	time_t	current_time;

	info = (t_info *)param;
	current_time = time(NULL);
	if (current_time % 2 == 0)
	{
		destroy_images(info);
		info->w_img = initialise_text_images_helper(info, info->we);
		info->e_img = initialise_text_images_helper(info, info->ea);
		info->n_img = initialise_text_images_helper(info, info->no);
		info->s_img = initialise_text_images_helper(info, info->so);
	}
	else
	{
		destroy_images(info);
		info->w_img = initialise_text_images_helper(info, info->no);
		info->e_img = initialise_text_images_helper(info, info->so);
		info->n_img = initialise_text_images_helper(info, info->we);
		info->s_img = initialise_text_images_helper(info, info->ea);
	}
	raycasting(info);
	return (0);
}

void	begin_game(t_info *info)
{
	if (check_text_path_exists("./textures/hands.xpm") \
		|| check_text_path_exists("./textures/gun_wall.xpm"))
		exit(perr("Missing animation textures\n"));
	inititialise_mlx_vals(info);
	set_directions(info);
	initialise_text_images(info);
	initialise_animation(info);
	raycasting(info);
	mlx_hook(info->win_ptr, 2, 1L << 0, key_hooks, info);
	mlx_hook(info->win_ptr, 6, 1L << 6, mv_mouse, info);
	mlx_hook(info->win_ptr, 17, 1L << 17, &quit, info);
	mlx_loop_hook(info->mlx_ptr, switch_textures, info);
	mlx_loop(info->mlx_ptr);
}
