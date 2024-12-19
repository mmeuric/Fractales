/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:34:23 by mmeuric           #+#    #+#             */
/*   Updated: 2024/12/17 19:04:07 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESIGN_H
# define DESIGN_H

# include "fractal.h"

void	set_pixel_color(t_engine *engine, int x, int y, int color);
void	change_color(int key, t_engine *engine);
void	change_view(int key, t_engine *engine);
int		calc_fractal(t_fractal *fract, t_complex *c, int x, int y);
void	draw_fractal(t_engine *engine);

#endif
