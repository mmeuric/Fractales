/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:38:42 by mmeuric           #+#    #+#             */
/*   Updated: 2024/12/19 04:48:46 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine_init.h"
#include "mlx.h"
#include "action.h"
#include "design.h"

int	on_destroy_event(t_engine *engine)
{
	mlx_destroy_image(engine->mlx, engine->image.img_ptr);
	mlx_destroy_window(engine->mlx, engine->window);
	exit(EXIT_SUCCESS);
}

int	on_mouse_hook_event(int key, int x, int y, t_engine *engine)
{
	t_fractal	*fr;

	fr = &engine->fractal;
	if (key == MOUSE_SCRL_DOWN)
	{
		fr->offset_x = (x / fr->zoom + fr->offset_x) - (x / (fr->zoom / 1.3));
		fr->offset_y = (y / fr->zoom + fr->offset_y) - (y / (fr->zoom / 1.3));
		fr->zoom /= 1.3;
	}
	else if (key == MOUSE_SCRL_UP)
	{
		fr->offset_x = (x / fr->zoom + fr->offset_x) - (x / (fr->zoom * 1.3));
		fr->offset_y = (y / fr->zoom + fr->offset_y) - (y / (fr->zoom * 1.3));
		fr->zoom *= 1.3;
	}
	draw_fractal(engine);
	return (0);
}

int	on_key_hook_event(int key, t_engine *engine)
{
	if ((key == KEY_Q || key == KEY_W) || (key == KEY_A || key == KEY_S))
		change_color(key, engine);
	else if (key >= KEY_LEFT && key <= KEY_UP)
		change_view(key, engine);
	else if (key >= KEY_RIGHT && key <= KEY_DOWN)
		change_view(key, engine);
	else if (key >= KEY_ONE && key <= KEY_FOUR)
		change_fractal(key, engine);
	else if (key == KEY_L && engine->fractal.type == JULIA)
		engine->fractal.is_julia_lock ^= 1;
	else if (key == KEY_ZERO)
		reset_engine(engine, engine->fractal.type);
	else if (key == KEY_ESC)
		on_destroy_event(engine);
	draw_fractal(engine);
	return (0);
}

int	on_mousemove_event(int x, int y, t_engine *engine)
{
	if (!(engine->fractal.type == JULIA) || engine->fractal.is_julia_lock)
		return (0);
	engine->fractal.mouse_x = x;
	engine->fractal.mouse_y = y;
	draw_fractal(engine);
	return (0);
}
