/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:28:29 by mmeuric           #+#    #+#             */
/*   Updated: 2024/12/21 03:16:05 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine_init.h"
#include "utils.h"
#include "action.h"
#include "mlx.h"

void	change_fractal(int key, t_engine *engine)
{
	reset_engine(engine, MANDELBROT);
	if (key == KEY_TWO)
		engine->fractal.type = JULIA;
	else if (key == KEY_THREE)
		engine->fractal.type = BURNING_SHIP;
	else if (key == KEY_FOUR)
		engine->fractal.type = TRICORN;
}

void	set_fractal_type(t_engine *engine, char *str)
{
	size_t	len;

	if (!engine || !str)
		return ;
	ft_strlower(str);
	len = ft_strlen(str);
	if (ft_strncmp(str, MANDELBROT_STR, len) == 0)
		engine->fractal.type = MANDELBROT;
	else if (ft_strncmp(str, JULIA_STR, len) == 0)
		engine->fractal.type = JULIA;
	else if (ft_strncmp(str, BURNING_SHIP_STR, len) == 0)
		engine->fractal.type = BURNING_SHIP;
	else if (ft_strncmp(str, TRICORN_STR, len) == 0)
		engine->fractal.type = TRICORN;
	else
		show_help();
}

void	reset_engine(t_engine *engine, int fractal_type)
{
	engine->fractal.type = fractal_type;
	engine->fractal.zoom = WIN_SIZE / 4;
	engine->fractal.mouse_x = 0;
	engine->fractal.mouse_y = 0;
	engine->fractal.offset_x = -2;
	engine->fractal.offset_y = -2;
	engine->fractal.is_julia_lock = false;
	engine->fractal.color = DEFAULT_COLOR;
	engine->fractal.iterations = MAX_ITERATIONS;
}

void	init_engine(t_engine *engine, char *str)
{
	int	pixel_bits;
	int	line_len;
	int	endian;

	if (!engine || !str)
		return ;
	reset_engine(engine, MANDELBROT);
	set_fractal_type(engine, str);
	engine->mlx = mlx_init();
	if (!engine->mlx)
		error_message("[MLX ERROR]: can't do mlx_init!\n", 1);
	engine->window = mlx_new_window(engine->mlx, WIN_SIZE, WIN_SIZE, \
												"Fractol project");
	engine->image.img_ptr = mlx_new_image(engine->mlx, WIN_SIZE, WIN_SIZE);
	if (!engine->window || !engine->image.img_ptr)
		on_destroy_event(engine);
	engine->image.addr_ptr = mlx_get_data_addr(engine->image.img_ptr, \
								&pixel_bits, &line_len, &endian);
	engine->image.pixel_bits = pixel_bits;
	engine->image.line_len = line_len;
	engine->image.endian = endian;
}
