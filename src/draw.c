/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:13:21 by malluin           #+#    #+#             */
/*   Updated: 2018/12/05 11:59:05 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	draw_grid(t_win *mlx)
{
	int		i;
	int		j;
	t_pix	*px;
	t_pix	*px2;

	i = -1;
	while (++i < mlx->map->size_y)
	{
		j = 0;
		while (j < mlx->map->size_x)
		{
			px = &(mlx->screen[i][j]);
			if (j != mlx->map->size_x - 1)
			{
				px2 = &(mlx->screen[i][j + 1]);
				place_line(mlx, *px, *px2);
			}
			if (i != mlx->map->size_y - 1)
			{
				px2 = &(mlx->screen[i + 1][j]);
				place_line(mlx, *px, *px2);
			}
			j++;
		}
	}
}
