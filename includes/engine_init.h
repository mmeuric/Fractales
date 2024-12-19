/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_init.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:34:05 by mmeuric           #+#    #+#             */
/*   Updated: 2024/12/17 19:03:13 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_INIT_H
# define ENGINE_INIT_H

# include "fractal.h"

void	change_fractal(int key, t_engine *engine);
void	set_fractal_type(t_engine *engine, char *str);
void	reset_engine(t_engine *engine, int fractal_type);
void	init_engine(t_engine *engine, char *arg);

#endif
