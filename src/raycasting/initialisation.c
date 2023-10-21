/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:00:39 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/08 17:26:10 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*initialise_text_images_helper(t_info *info, char *path)
{
	t_img	*new_image;

	new_image = malloc(sizeof(t_img));
	if (!new_image)
		exit (perr("Fatal Error: unable to malloc\n"));
	new_image->img = mlx_xpm_file_to_image(info->mlx_ptr, path, \
		&new_image->iw, &new_image->ih);
	new_image->addr = (int *)mlx_get_data_addr(new_image->img, &new_image->bpp, \
		&new_image->ll, &new_image->endian);
	return (new_image);
}

void	initialise_text_images(t_info *info)
{
	info->n_img = initialise_text_images_helper(info, info->no);
	info->s_img = initialise_text_images_helper(info, info->so);
	info->w_img = initialise_text_images_helper(info, info->we);
	info->e_img = initialise_text_images_helper(info, info->ea);
	return ;
}

void	inititialise_mlx_vals(t_info *info)
{
	info->mv_speed = 0.15;
	info->rt_speed = 0.15;
	info->mlx_ptr = mlx_init();
	if (!(info->mlx_ptr))
	{
		free_everything(info);
		exit(perr("Failure to initialise mlx ptr\n"));
	}
	info->win_ptr = mlx_new_window(info->mlx_ptr, info->sw, info->sh, "cub3d");
	if (!(info->win_ptr))
	{
		free_everything(info);
		exit(perr("Failure to initialise win ptr\n"));
	}
}
