/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:37:52 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/07/01 12:09:06 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*memory[OPEN_MAX];
	char		*pure_line;
	int			line_length;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX || read(fd, NULL, 0) < 0)
		return (NULL);
	initialize_memory(&memory[fd]);
	if (memory[fd] == NULL)
		return (NULL);
	if (include_new_line(memory[fd]) == 0)
	{
		memory[fd] = generate_line(fd, memory[fd]);
		if (memory[fd] == NULL)
			return (NULL);
	}
	line_length = get_line_len(memory[fd]);
	if (line_length == 0)
		return (free_and_set_null(&memory[fd]));
	pure_line = (char *)malloc(sizeof(char) * (line_length + 1));
	if (pure_line == NULL)
		return (free_and_set_null(&memory[fd]));
	ft_strlcpy(pure_line, memory[fd], (line_length + 1));
	memmove_left(memory[fd], line_length);
	return (pure_line);
}

char	*generate_line(int fd, char *memory)
{
	int		read_count;
	char	*buffer;

	while (1)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return (free_and_set_null(&memory));
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count < 0)
		{
			free_and_set_null(&buffer);
			return (free_and_set_null(&memory));
		}
		buffer[read_count] = '\0';
		memory = ft_strjoin(memory, buffer);
		free_and_set_null(&buffer);
		if (include_new_line(memory) == 1 || read_count == 0)
			return (memory);
	}
}

void	initialize_memory(char **memory)
{
	if (memory == NULL)
		return ;
	if (*memory == NULL)
	{
		*memory = (char *)malloc(sizeof(char) * 1);
		if (*memory == NULL)
			return ;
		**memory = '\0';
	}
}

char	*free_and_set_null(char **should_be_free)
{
	free(*should_be_free);
	*should_be_free = NULL;
	return (NULL);
}

int	include_new_line(char *buf)
{
	int	index;

	index = 0;
	if (buf == NULL)
		return (-1);
	while (buf[index] != '\0')
	{
		if (buf[index] == '\n')
			return (1);
		else
			index += 1;
	}
	return (0);
}
