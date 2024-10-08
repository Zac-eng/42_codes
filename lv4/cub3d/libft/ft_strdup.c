/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:50:58 by yususato          #+#    #+#             */
/*   Updated: 2024/08/27 11:18:27 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		count;
	char	*new;

	i = 0;
	count = 0;
	if (src == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		count++;
		i++;
	}
	new = (char *)malloc(sizeof(char) * (count + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
