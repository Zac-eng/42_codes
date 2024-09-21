/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:36:14 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/07 14:21:50 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit(long int n);
static void	int_dup(char *dst, long int n, int index);
static void	*safe_malloc(int n, int digit);

char	*ft_itoa(int n)
{
	long int	long_n;
	int			digit;
	char		*num_str;

	long_n = n;
	digit = get_digit(n);
	num_str = (char *)safe_malloc(n, digit);
	if (num_str == NULL)
		return (NULL);
	if (n < 0)
	{
		num_str[0] = '-';
		int_dup(num_str + 1, long_n * -1, digit - 1);
		num_str[digit + 1] = '\0';
	}
	else
	{
		int_dup(num_str, n, digit - 1);
		num_str[digit] = '\0';
	}
	return (num_str);
}

static int	get_digit(long int n)
{
	int	digit;

	digit = 1;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		n /= 10;
		digit += 1;
	}
	return (digit);
}

static void	int_dup(char *dst, long int n, int index)
{
	if (n >= 10)
		int_dup(dst, n / 10, index - 1);
	dst[index] = (n % 10) + '0';
}

static void	*safe_malloc(int n, int digit)
{
	void	*num_str;

	if (n < 0)
		num_str = malloc(sizeof(char) * digit + 2);
	else
		num_str = malloc(sizeof(char) * digit + 1);
	if (num_str == NULL)
		return (NULL);
	else
		return (num_str);
}
