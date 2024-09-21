/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:21:42 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/05/28 15:08:00 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_str(char *large, char *small, size_t left);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hs_local;
	char	*nl_local;
	size_t	searched;

	searched = 0;
	hs_local = (char *) haystack;
	nl_local = (char *) needle;
	if (*needle == '\0')
		return (hs_local);
	while (searched < len && *hs_local != '\0')
	{
		while (*hs_local != *needle && *hs_local != '\0' && searched < len)
		{
			hs_local += 1;
			searched += 1;
		}
		if (check_str(hs_local, nl_local, len - searched) == 1)
			return (hs_local);
		else
		{
			hs_local += 1;
			searched += 1;
		}
	}
	return (NULL);
}

static int	check_str(char *large, char *small, size_t left)
{
	while (*large != '\0' && *small != '\0' && left > 0)
	{
		if (*large != *small)
			return (0);
		else
		{
			large += 1;
			small += 1;
			left -= 1;
		}
	}
	if (*small == '\0')
		return (1);
	else
		return (0);
}
