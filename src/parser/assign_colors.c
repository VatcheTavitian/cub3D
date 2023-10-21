/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:02:30 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/17 16:00:20 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	assign_f_field(int field, int num, t_info *info)
{
	if (num < 0 || num > 255)
	{
		perr("Colors out of range\n");
		exit(1);
	}
	if (field == 1)
		info->f1 = num;
	else if (field == 2)
		info->f2 = num;
	else if (field == 3)
		info->f3 = num;
}

int	assign_color_vals_f(t_info *info, char *x)
{
	int		i;
	int		num;
	int		field;

	field = 1;
	i = 0;
	num = 0;
	while (x[i])
	{
		if (x[i] && x[i] != ',')
		{
			num = 0;
			while (x[i] && x[i] != ',')
			{
				num = (num * 10) + (x[i] - 48);
				i++;
			}
			assign_f_field(field, num, info);
			field++;
		}
		else
			i++;
	}
	return (0);
}

static void	assign_c_field(int field, int num, t_info *info)
{
	if (num < 0 || num > 255)
	{
		perr("Colors out of range\n");
		exit(1);
	}
	if (field == 1)
		info->c1 = num;
	else if (field == 2)
		info->c2 = num;
	else if (field == 3)
		info->c3 = num;
}

int	assign_color_vals_c(t_info *info, char *x)
{
	int		i;
	int		num;
	char	*path;
	int		field;

	field = 1;
	i = 0;
	num = 0;
	while (x[i])
	{
		if (x[i] && x[i] != ',')
		{
			num = 0;
			while (x[i] && x[i] != ',')
			{
				num = (num * 10) + (x[i] - 48);
				i++;
			}
			assign_c_field(field, num, info);
			field++;
		}
		else
			i++;
	}
	return (0);
}
