/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:29:03 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/31 20:24:28 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <float.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
	double	*c;
	double	range;
	int		size[2];
}				t_vars;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_pass {
	t_vars	*v;
	t_data	*i;
}				t_pass;

void	show_input_choice(void);
void	create_julia_image(t_data *img, t_vars *v);
void	julia_operation(double *z0);
void	create_mandelbrot_image(t_data *img, t_vars *v);
void	mandelbrot_operation(void);
void	mlx_window_options(t_vars *vars, t_data *img);
int		escape_close(int keycode, t_vars *vars);
int		cross_close(int keycode);
int		resize(int keycode, int x, int y, t_pass *passing);
void	put_pixel_img(t_data *data, int x, int y, int color);
void	init_data(t_vars *v, t_data *d);
int		ft_strcmp(char *lhs, char *rhs);
double	ft_atof(char *input);

#endif
