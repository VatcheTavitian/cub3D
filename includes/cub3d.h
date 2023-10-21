/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:30:06 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/18 15:56:25 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include "../minilibx/mlx.h"
# include "libft.h"
# include <math.h>

typedef struct s_img {
	void	*img;
	int		*addr;
	char	**data;
	int		bpp;
	int		ll;
	int		endian;
	int		iw;
	int		ih;
}	t_img;

typedef struct s_info {
	char	**map;
	char	dir;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*image;
	t_img	*wall_texture;
	t_img	*n_img;
	t_img	*s_img;
	t_img	*e_img;
	t_img	*w_img;
	t_img	*hands_img;
	t_img	*gun_wall_img;
	int		filefd;
	char	*mpath;
	char	**content;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*c;
	char	*f;
	int		f1;
	int		f2;
	int		f3;
	int		fcol;
	int		c1;
	int		c2;
	int		c3;
	int		ccol;
	int		lines;
	int		map_lines;
	int		x_texture;
	int		y_texture;
	int		texture_height;
	int		mapx;
	int		mapy;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		color;
	int		xstep;
	int		ystep;
	int		side;
	int		mw;
	int		mh;
	int		sw;
	int		sh;
	int		hit;
	int		exit;
	double	pposx;
	double	pposy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	x_cam;
	double	cameray;
	double	raydirection_x;
	double	raydirection_y;
	double	olddirx;
	double	oldplanex;
	double	delta_x;
	double	delta_y;
	double	perpwalldist;
	double	wallx;
	double	x_side_dist;
	double	y_side_dist;
	double	mv_speed;
	double	rt_speed;

}	t_info;

int		validate_map_file(int argc, char **argv, t_info *info);
int		count_dots(char *name);
int		perr(char *s);
int		ft_strcmp(char *s1, char *s2);
int		check_map_content(t_info *info);
int		check_each_line(int lines, t_info *info);
void	free_all(char **array);
void	read_to_array(int fd, int move, char **content, t_info *info);
int		check_text_path_exists(char *path);
void	assign_textures(t_info *info);
int		id_in_list(char *id);
int		assign_color_vals_c(t_info *info, char *x);
int		assign_color_vals_f(t_info *info, char *x);
void	process_colors(t_info *info);
void	copy_map(t_info *info, int start);
void	delete_content(t_info *info);
void	parse_map(t_info *info);
void	check_map_chars(t_info *info);
int		just_ws(char *s);
void	validate_result(int n, int s, int w, int e);
void	check_fields_before_map(t_info *info, int start);
void	check_map_wrap(t_info *info);
int		arrsize(char **arr);
void	assign_dir(t_info *info);
void	free_everything(t_info *info);
void	assign_dir(t_info *info);
int		arrsize(char **arr);
int		check_below_map(t_info *info, int i);
int		one_or_space(char *s);
int		check_below(t_info *info, int i);
void	set_map_lines(t_info *info);

//Raycasting
void	begin_game(t_info *info);
int		key_hooks(int key, t_info *info);
void	raycasting(t_info *info);
void	initialise_text_images(t_info *info);
void	inititialise_mlx_vals(t_info *info);
void	set_directions(t_info *info);
void	render_fc(t_info *info);
int		move(int key, t_info *info);
void	check_wall_hit(t_info *info);
void	find_ray_intersections(t_info *info);
void	set_params(t_info *info, int x);
void	set_params_wall_render(t_info *info);
t_img	*initialise_text_images_helper(t_info *info, char *path);
void	destroy_images(t_info *info);
void	initialise_animation(t_info *info);

#endif