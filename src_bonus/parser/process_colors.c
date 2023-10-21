/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:46:42 by vtavitia          #+#    #+#             */
/*   Updated: 2023/10/17 14:35:47 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_color_vals(char *x)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (x[i])
	{
		if (x[i] != ',' && !ft_isdigit(x[i]))
			return (perr("Invalid character in color configurations\n"));
		if (x[i] == ',')
		{
			count++;
			if (i == 0 || i == ft_strlen(x) - 1)
				return (perr("Invalid color configuration for ceiling/floor\n"));
			else if (!ft_isdigit(x[i - 1]) || \
				(x[i + 1] && !ft_isdigit(x[i + 1])))
				return (perr("Invalid color configuration for ceiling/floor\n"));
			i++;
		}
		i++;
	}
	if (count != 2)
		return (perr("Invalid color configuration for ceiling or floor\n"));
	return (0);
}

void	process_colors(t_info *info)
{
	int	i;
	int	value;

	i = 0;
	if (check_color_vals(info->c) || check_color_vals(info->f))
		exit(1);
	if (assign_color_vals_c(info, info->c) \
		|| assign_color_vals_f(info, info->f))
		exit(1);
}
