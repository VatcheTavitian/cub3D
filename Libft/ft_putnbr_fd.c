/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:40:20 by vtavitia          #+#    #+#             */
/*   Updated: 2023/01/26 12:50:41 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		num;
	long int	n1;

	n1 = n;
	if (n1 < 0)
	{
		write(fd, "-", 1);
		n1 *= -1;
	}
	if (n1 >= 10)
	{
		ft_putnbr_fd(n1 / 10, fd);
		n1 = n1 % 10;
	}
	num = n1 + 48;
	write(fd, &num, 1);
}
