/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:36:18 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/11 11:02:50 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_count(char const *s, char separator);
static int	word_len(char *s, char separator);
static char	*word_print(char **ref_original, char separator);
static void	list_clear(char **list_head, int str_count);

char	**ft_split(char const *s, char c)
{
	char	*s_local;
	char	**str_array;
	int		words_num;
	int		print_count;

	if (s == NULL)
		return (NULL);
	s_local = (char *)s;
	words_num = words_count(s, c);
	str_array = (char **)malloc(sizeof(char *) * (words_num + 1));
	if (str_array == NULL)
		return (NULL);
	print_count = 0;
	while (print_count < words_num)
	{
		str_array[print_count] = word_print(&s_local, c);
		if (str_array[print_count] == NULL)
		{
			list_clear(str_array, print_count);
			return (NULL);
		}
		print_count += 1;
	}
	str_array[print_count] = NULL;
	return (str_array);
}

static int	words_count(char const *s, char separator)
{
	char	*s_local;
	int		word_count;

	s_local = (char *)s;
	word_count = 0;
	while (*s_local && *s_local == separator)
		s_local += 1;
	while (*s_local)
	{
		word_count += 1;
		while (*s_local != separator && *s_local)
			s_local += 1;
		while (*s_local && *s_local == separator)
			s_local += 1;
	}
	return (word_count);
}

static int	word_len(char *s, char separator)
{
	int	len_count;

	len_count = 0;
	while (*s != separator && *s)
	{
		len_count += 1;
		s += 1;
	}
	return (len_count);
}

static char	*word_print(char **ref_original, char separator)
{
	char	*word_ptr;
	char	*ret_ptr;
	int		word_length;

	while (**ref_original == separator)
		*ref_original += 1;
	word_length = word_len(*ref_original, separator);
	word_ptr = (char *)malloc(sizeof(char) * word_length);
	if (word_ptr == NULL)
		return (NULL);
	ret_ptr = word_ptr;
	while (**ref_original != separator && **ref_original)
	{
		*word_ptr = **ref_original;
		word_ptr += 1;
		*ref_original += 1;
	}
	*word_ptr = '\0';
	return (ret_ptr);
}

static void	list_clear(char **list_head, int str_count)
{
	int	freed_count;

	freed_count = 0;
	while (freed_count < str_count)
		free(list_head[freed_count]);
	free(list_head);
}
