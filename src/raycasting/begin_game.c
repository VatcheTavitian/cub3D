/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:20:18 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/08 18:30:28 by vtavitia         ###   ########.fr       */
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

int	key_hooks(int key, t_info *info)
{
	if (key == 53)
	{
		mlx_destroy_window(info->mlx_ptr, info->win_ptr);
		exit(1);
	}
	if (key == 126 || key == 125 || key == 124 || key == 123 \
	|| key == 0 || key == 1 || key == 2 || key == 13)
		move(key, info);
	return (0);
}

void	begin_game(t_info *info)
{
	inititialise_mlx_vals(info);
	set_directions(info);
	initialise_text_images(info);
	raycasting(info);
	mlx_hook(info->win_ptr, 2, 1L << 0, key_hooks, info);
	mlx_hook(info->win_ptr, 17, 1L << 17, &quit, info);
	mlx_loop(info->mlx_ptr);
	mlx_loop_hook(info->mlx_ptr, quit, info);
}
