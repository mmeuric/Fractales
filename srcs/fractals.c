/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:27:35 by mmeuric           #+#    #+#             */
/*   Updated: 2024/12/19 02:54:17 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <math.h>

int	calc_mandelbrot(t_fractal *fract, t_complex *c)
{
	double		re_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.re = 0;
	z.im = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
	{
		re_temp = z.re * z.re - z.im * z.im + c->re;
		z.im = 2 * z.re * z.im + c->im;
		z.re = re_temp;
	}
	return (i);
}

int	calc_julia(t_fractal *fract, t_complex *c, int x, int y)
{
	double		re_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.re = (x / fract->zoom) + fract->offset_x;
	z.im = (y / fract->zoom) + fract->offset_y;
	while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
	{
		re_temp = z.re * z.re - z.im * z.im + c->re;
		z.im = 2 * z.re * z.im + c->im;
		z.re = re_temp;
	}
	return (i);
}

int	calc_burning_ship(t_fractal *fract, t_complex *c)
{
	double		re_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.re = 0;
	z.im = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
	{
		re_temp = z.re * z.re - z.im * z.im + c->re;
		z.im = fabs(2 * z.re * z.im) + c->im;
		z.re = fabs(re_temp);
	}
	return (i);
}

int	calc_tricorn(t_fractal *fract, t_complex *c)
{
	double		re_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.re = 0;
	z.im = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
	{
		re_temp = z.re * z.re - z.im * z.im + c->re;
		z.im = -2 * z.re * z.im + c->im;
		z.re = re_temp;
	}
	return (i);
}
