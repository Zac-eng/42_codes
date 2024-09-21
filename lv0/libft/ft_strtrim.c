/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:50:31 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/08 15:23:41 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char s1, char *set);
static int	nothing_after(char *str, char *set);
static void	trim_copy(char *trimmed, char *s1, char *set);
static int	get_trimmed_len(char *to_be_trimmed, char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_local;
	char	*set_local;
	char	*trimmed_ptr;
	int		trimmed_len;

	if (s1 == NULL || set == NULL)
		return ((char *)s1);
	s1_local = (char *)s1;
	set_local = (char *)set;
	trimmed_len = get_trimmed_len(s1_local, set_local);
	trimmed_ptr = (char *)malloc(sizeof(char) * trimmed_len + 1);
	if (trimmed_ptr == NULL)
		return (NULL);
	while (is_set(*s1_local, set_local) == 1)
		s1_local += 1;
	trim_copy(trimmed_ptr, s1_local, set_local);
	return (trimmed_ptr);
}

static int	get_trimmed_len(char *to_be_trimmed, char *set)
{
	int	trimmed_len;

	trimmed_len = 0;
	while (is_set(*to_be_trimmed, set) == 1)
		to_be_trimmed += 1;
	while (*to_be_trimmed)
	{
		if (is_set(*to_be_trimmed, set) == 1)
		{
			if (nothing_after(to_be_trimmed, set) == 1)
				return (trimmed_len);
		}
		trimmed_len += 1;
		to_be_trimmed += 1;
	}
	return (trimmed_len);
}

static int	is_set(char s1, char *set)
{
	while (*set != '\0')
	{
		if (s1 == *set)
			return (1);
		else
			set += 1;
	}
	return (0);
}

static int	nothing_after(char *str, char *set)
{
	while (*str)
	{
		if (is_set(*str, set) == 0)
			return (0);
		else
			str += 1;
	}
	return (1);
}

static void	trim_copy(char *trimmed, char *s1, char *set)
{
	while (*s1 != '\0')
	{
		if (is_set(*s1, set) == 1)
		{
			if (nothing_after(s1, set) == 1)
			{
				*trimmed = '\0';
				return ;
			}
		}
		*trimmed = *s1;
		trimmed += 1;
		s1 += 1;
	}
	*trimmed = '\0';
	return ;
}
