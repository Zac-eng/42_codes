/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:36:05 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/07/01 12:03:40 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*generate_line(int fd, char *memory);
int		get_line_len(char *buf);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dtsize);
void	memmove_left(char *memory, int displacement);
void	initialize_memory(char **memory);
int		include_new_line(char *buf);
char	*free_and_set_null(char **should_be_free);
size_t	ft_strlen(const char *s);

#endif