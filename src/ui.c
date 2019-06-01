/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:20:20 by malluin           #+#    #+#             */
/*   Updated: 2018/12/05 15:40:25 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	boxes(t_win *mlx)
{
	int i;
	int j;

	i = 0;
	while (i < HEIGHT / 25)
	{
		j = 0;
		while (j < WIDTH)
			place_pixel(mlx, j++, i, rgb(100, 185, 200));
		j = 0;
		i++;
	}
	i = HEIGHT - HEIGHT / 25;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			place_pixel(mlx, j++, i, rgb(100, 185, 200));
		j = 0;
		i++;
	}
}

void	legend_box(t_win *mlx)
{
	int i;
	int j;

	i = HEIGHT / 6;
	while (i < HEIGHT / 2)
	{
		j = WIDTH - WIDTH / 6;
		while (j < WIDTH - 15)
			place_pixel(mlx, j++, i, rgb(255, 255, 255));
		j = 0;
		i++;
	}
}

void	legend_text(t_win *mlx)
{
	int i;
	int j;
	int c;

	c = 1;
	i = HEIGHT / 6;
	j = WIDTH - WIDTH / 6 + 5;
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, j, i,
		rgb(55, 55, 55), "Isometric view on/off: I");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, j, i + HEIGHT / 50 * c++,
		rgb(55, 55, 55), "Reset view: R");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, j, i + HEIGHT / 50 * c++,
		rgb(55, 55, 55), "Rotate X: Arrow up/down");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, j, i + HEIGHT / 50 * c++,
		rgb(55, 55, 55), "Rotate Y: Arrow left/right");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, j, i + HEIGHT / 50 * c++,
		rgb(55, 55, 55), "Rotate Z: Page Up/Down");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, j, i + HEIGHT / 50 * c++,
		rgb(55, 55, 55), "Zoom: Home(+)/End(-)");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, j, i + HEIGHT / 50 * c++,
		rgb(55, 55, 55), "Modify altitude: '-' / '+'");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, j, i + HEIGHT / 50 * (c + 1),
		rgb(55, 55, 55), "Exit: Escape");
}
