/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:28:52 by mmeuric           #+#    #+#             */
/*   Updated: 2024/12/17 17:11:56 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "design.h"

void	change_view(int key, t_engine *engine)
{
	t_fractal	*fractal;

	fractal = &engine->fractal;
	if (key == KEY_LEFT)
		fractal->offset_x -= VIEW_CHANGE_SIZE / fractal->zoom;
	else if (key == KEY_RIGHT)
		fractal->offset_x += VIEW_CHANGE_SIZE / fractal->zoom;
	else if (key == KEY_UP)
		fractal->offset_y -= VIEW_CHANGE_SIZE / fractal->zoom;
	else if (key == KEY_DOWN)
		fractal->offset_y += VIEW_CHANGE_SIZE / fractal->zoom;
}

void	change_color(int key, t_engine *engine)
{
	if (key == KEY_Q)
		engine->fractal.color += 0x500000;
	else if (key == KEY_W)
		engine->fractal.color += 0x000050;
	else if (key == KEY_A)
		engine->fractal.color -= 0x500000;
	else if (key == KEY_S)
		engine->fractal.color -= 0x000050;
}

void	set_pixel_color(t_engine *engine, int x, int y, int color)
{
	int	line_len;
	int	pixel_bits;
	int	offset;

	if (x < 0 || x >= WIN_SIZE || y < 0 || y >= WIN_SIZE)
		return ;
	line_len = engine->image.line_len;
	pixel_bits = engine->image.pixel_bits;
	offset = (y * line_len) + ((pixel_bits / 8) * x);
	*(unsigned int *)(engine->image.addr_ptr + offset) = color;
}

int	calc_fractal(t_fractal *fract, t_complex *c, int x, int y)
{
	int	iter;

	iter = 0;
	if (fract->type != JULIA)
		c->im = (y / fract->zoom) + fract->offset_y;
	else if (!fract->is_julia_lock)
		c->im = (fract->mouse_y / fract->zoom) + fract->offset_y;
	if (fract->type == MANDELBROT)
		iter = calc_mandelbrot(fract, c);
	else if (fract->type == JULIA)
		iter = calc_julia(fract, c, x, y);
	else if (fract->type == BURNING_SHIP)
		iter = calc_burning_ship(fract, c);
	else if (fract->type == TRICORN)
		iter = calc_tricorn(fract, c);
	return (iter);
}

void	draw_fractal(t_engine *engine)
{
	static t_complex	c;
	t_fractal			*fract;
	int					iter;
	int					x;
	int					y;

	x = -1;
	fract = &engine->fractal;
	mlx_clear_window(engine->mlx, engine->window);
	while (++x < WIN_SIZE)
	{
		y = -1;
		if (fract->type != JULIA)
			c.re = (x / fract->zoom) + fract->offset_x;
		else if (!fract->is_julia_lock)
			c.re = (fract->mouse_x / fract->zoom) + fract->offset_x;
		while (++y < WIN_SIZE)
		{
			iter = calc_fractal(fract, &c, x, y);
			set_pixel_color(engine, x, y, (iter * fract->color));
		}
	}
	mlx_put_image_to_window(engine->mlx, engine->window, \
							engine->image.img_ptr, 0, 0);
}
