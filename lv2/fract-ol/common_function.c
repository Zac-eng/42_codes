/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:36:08 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/31 21:40:27 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_window_options(t_vars *vars, t_data *img)
{
	mlx_hook(vars->win, 2, 1L << 0, escape_close, vars);
	mlx_hook(vars->win, 17, 1L << 2, cross_close, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	mlx_loop(vars->mlx);
}

void	put_pixel_img(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (data == NULL)
		exit(1);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_data(t_vars *v, t_data *d)
{
	if (v == NULL || d == NULL)
		exit(1);
	d->img = mlx_new_image(v->mlx, v->size[0], v->size[1]);
	if (d->img == NULL)
		exit(1);
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, \
		&d->endian);
	if (d->addr == NULL)
		exit(1);
}
