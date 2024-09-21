/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:51:39 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/31 21:37:22 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_in_screen(int *size, int x, int y);

int	escape_close(int keycode, t_vars *vars)
{
	if (vars == NULL)
		exit(1);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	cross_close(int keycode)
{
	if (keycode < 0)
		exit(0);
	else
		return (0);
}

int	resize(int keycode, int x, int y, t_pass *p)
{
	if (p == NULL || p->i == NULL || p->v == NULL)
		exit(1);
	if (is_in_screen(p->v->size, x, y) == 0)
		exit(0);
	if (keycode == 4 || keycode == 5)
	{
		if (keycode == 4)
			p->v->range *= 0.9;
		if (keycode == 5)
			p->v->range *= 1.1;
		if (p->v->c != NULL)
		{
			create_julia_image(p->i, p->v);
			mlx_put_image_to_window(p->v->mlx, p->v->win, p->i->img, 0, 0);
		}
		else
		{
			create_mandelbrot_image(p->i, p->v);
			mlx_put_image_to_window(p->v->mlx, p->v->win, p->i->img, 0, 0);
		}
	}
	return (0);
}

static int	is_in_screen(int *size, int x, int y)
{
	if (size == NULL)
		exit(1);
	if (x < 0 || x > size[0])
		return (0);
	if (y < 0 || y > size[1])
		return (0);
	return (1);
}
