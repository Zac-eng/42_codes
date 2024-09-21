/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:03:55 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/08 10:58:28 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_unbr(unsigned int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n_local;

	if (n < 0)
	{
		write(fd, "-", 1);
		n_local = n * -1;
	}
	else
		n_local = n;
	put_unbr(n_local, fd);
}

static void	put_unbr(unsigned int n, int fd)
{
	char	remainder_char;

	remainder_char = (n % 10) + '0';
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	write(fd, &remainder_char, 1);
}
