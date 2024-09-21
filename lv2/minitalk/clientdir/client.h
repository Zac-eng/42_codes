/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:42:24 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/16 17:08:03 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include "../ft_printf/ft_printf.h"

int		check_input(int argc, char *arg_pid);
int		send_charactor(int pid, unsigned char charactor);
int		read_pid(char *str);

#endif