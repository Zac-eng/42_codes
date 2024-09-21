/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:42:59 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/31 21:39:48 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	return_color(double *c);

void	mandelbrot_operation(void)
{
	t_vars	v;
	t_data	img;
	t_pass	passing;

	v.size[0] = 1080;
	v.size[1] = 1080;
	v.mlx = mlx_init();
	if (v.mlx == NULL)
		exit(1);
	v.win = mlx_new_window(v.mlx, v.size[0], v.size[1], "mandelbrot set");
	if (v.win == NULL)
		exit(1);
	init_data(&v, &img);
	if (img.img == NULL)
		exit(1);
	v.c = NULL;
	v.range = 3.0;
	passing.i = &img;
	passing.v = &v;
	create_mandelbrot_image(&img, &v);
	mlx_mouse_hook(v.win, resize, &passing);
	mlx_window_options(&v, &img);
}

void	create_mandelbrot_image(t_data *img, t_vars *v)
{
	double	c[2];
	int		iter[2];

	if (img == NULL || v == NULL)
		exit(1);
	iter[0] = 0;
	iter[1] = 0;
	while (iter[0] < v->size[0])
	{
		while (iter[1] < v->size[1])
		{
			c[0] = -1 * v->range + iter[0] * (v->range * 2) / v->size[0];
			c[1] = v->range - iter[1] * (v->range * 2) / v->size[1];
			put_pixel_img(img, iter[0], iter[1], return_color(&c[0]));
			iter[1] += 1;
		}
		iter[1] = 0;
		iter[0] += 1;
	}
}

static int	return_color(double *c)
{
	double	zn[2];
	double	zn_prev[2];
	int		iter;

	if (c == NULL)
		exit(1);
	iter = 0;
	zn[0] = 0.0;
	zn[1] = 0.0;
	while (iter < 100 && zn[0] * zn[0] + zn[1] * zn[1] < 4)
	{
		zn_prev[0] = zn[0];
		zn_prev[1] = zn[1];
		zn[0] = zn_prev[0] * zn_prev[0] - zn_prev[1] * zn_prev[1] + c[0];
		zn[1] = 2 * zn_prev[0] * zn_prev[1] + c[1];
		iter += 1;
	}
	if (zn[0] * zn[0] + zn[1] * zn[1] < 4)
		return (0x00FFFACD);
	else
		return (0x006A5ACD + (zn[0] * zn[0] + zn[1] * zn[1]) * 1.2);
}
