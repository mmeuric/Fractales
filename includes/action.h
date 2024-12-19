/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:33:08 by mmeuric           #+#    #+#             */
/*   Updated: 2024/12/17 19:04:25 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H

# include "fractal.h"

int	on_destroy_event(t_engine *engine);
int	on_mouse_hook_event(int key, int x, int y, t_engine *engine);
int	on_key_hook_event(int key, t_engine *engine);
int	on_mousemove_event(int x, int y, t_engine *engine);

#endif
