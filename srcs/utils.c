/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:29:00 by mmeuric           #+#    #+#             */
/*   Updated: 2024/12/21 22:43:45 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

void	error_message(char *text, int nb)
{
	if (nb == 0)
		perror(text);
	else if (text)
		ft_putstr_fd(text, 2);
	exit(EXIT_FAILURE);
}

void	ft_strlower(char *str)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
}

void	print(char *str, int fd)
{
	ft_putstr_fd(str, fd);
}

void	show_help(void)
{
	print("\n", 1);
	print(" +----------------------- TUTORIAL ------------------------+\n", 1);
	print(" |                                                         |\n", 1);
	print(" | Usage: ./fractol [m mandelbrot / j julia /              |\n", 1);
	print(" |                   b burning_ship / t tricorn]           |\n", 1);
	print(" |                                                         |\n", 1);
	print(" | e.g: ./fractol m                                        |\n", 1);
	print(" |                                                         |\n", 1);
	print(" |----------------------- KEYBOARD ------------------------|\n", 1);
	print(" |                                                         |\n", 1);
	print(" | Press ESC to close the window                           |\n", 1);
	print(" | Press one of [1 to 4] to move to another fractal        |\n", 1);
	print(" | Press one of [Q-W] keys to change the color++           |\n", 1);
	print(" | Press one of [A-S] keys to change the color--           |\n", 1);
	print(" | Use mouse scroll to zoom in and out of the fractal      |\n", 1);
	print(" | Press the arrow keys to change the viewpoint            |\n", 1);
	print(" | Press L to lock Julia's fractal                         |\n", 1);
	print(" | Press Zero to reset the fractal                         |\n", 1);
	print(" +---------------------------------------------------------+\n", 1);
	print("\n", 1);
	exit(EXIT_SUCCESS);
}
