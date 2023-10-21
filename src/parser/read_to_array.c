/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:51:50 by vtavitia          #+#    #+#             */
/*   Updated: 2023/09/26 12:21:54 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	copy_to_line(char *line, int chars, int fd)
{
	int	i;

	i = 0;
	while (i < chars)
	{
		read(fd, &(line[i]), 1);
		i++;
	}
	line[i] = '\0';
}

static int	count_chars(int fd)
{
	int		chars;
	char	buffer;

	chars = 0;
	while (read(fd, &buffer, 1) == 1)
	{
		if (buffer == '\n')
			break ;
		else
			chars++;
	}
	return (chars);
}

static void	shift_chars(int chars, int *fd, int total)
{
	int		target;
	int		i;
	char	buffer;

	i = 0;
	while (i < total)
	{
		read(*fd, &buffer, 1);
		i++;
	}
}

void	shift_new_fd(int move, int fd2)
{
	char	tmp;

	while (move-- > 0)
		read(fd2, &tmp, 1);
}

void	read_to_array(int fd, int move, char **content, t_info *info)
{
	int		i;
	int		fd2;
	char	*buffer;
	int		chars;
	int		total;

	total = 0;
	i = 0;
	while (i < info->lines)
	{
		chars = count_chars(fd) + 1;
		buffer = (char *)malloc(sizeof(char) * (chars + 1));
		fd2 = open(info->mpath, O_RDONLY);
		move = total;
		shift_new_fd(move, fd2);
		read(fd2, buffer, chars);
		buffer[chars - 1] = '\0';
		fd = fd2;
		total += chars;
		content[i] = ft_strdup(buffer);
		i++;
		free(buffer);
	}
	content[i] = NULL;
	info->content = content;
}
