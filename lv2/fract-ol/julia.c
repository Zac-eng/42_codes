/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:28:42 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/31 21:39:17 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	return_color(double *c, double *z0);

void	julia_operation(double *c)
{
	t_pass	passing;
	t_vars	v;
	t_data	img;

	if (c == NULL)
		show_input_choice();
	v.size[0] = 1080;
	v.size[1] = 1080;
	v.mlx = mlx_init();
	if (v.mlx == NULL)
		exit(1);
	v.win = mlx_new_window(v.mlx, v.size[0], v.size[1], "julia set");
	if (v.win == NULL)
		exit(1);
	init_data(&v, &img);
	if (img.img == NULL)
		exit(1);
	v.c = c;
	v.range = 3.0;
	passing.v = &v;
	passing.i = &img;
	create_julia_image(&img, &v);
	mlx_mouse_hook(v.win, resize, &passing);
	mlx_window_options(&v, &img);
}

void	create_julia_image(t_data *img, t_vars *v)
{
	double	z0[2];
	int		i[2];

	if (img == NULL || v == NULL)
		exit(1);
	i[0] = 0;
	i[1] = 0;
	while (i[0] < v->size[0])
	{
		while (i[1] < v->size[1])
		{
			z0[0] = -1 * v->range + i[0] * (v->range * 2) / v->size[0];
			z0[1] = v->range - i[1] * (v->range * 2) / v->size[1];
			put_pixel_img(img, i[0], i[1], return_color(v->c, &z0[0]));
			i[1] += 1;
		}
		i[1] = 0;
		i[0] += 1;
	}
}

static int	return_color(double *c, double *z0)
{
	double	zn[2];
	double	zn_prev[2];
	int		iter;

	if (c == NULL || z0 == NULL)
		exit(1);
	iter = 0;
	zn[0] = z0[0];
	zn[1] = z0[1];
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
