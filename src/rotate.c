/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:51:02 by malluin           #+#    #+#             */
/*   Updated: 2018/12/06 16:58:18 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	rotate(t_win *mlx, float ax, float ay, float az)
{
	int		i;
	int		j;
	int		py;
	int		px;
	t_coord	*pt;

	i = -1;
	while (++i < mlx->map->size_y)
	{
		j = -1;
		while (++j < mlx->map->size_x)
		{
			pt = &(mlx->proj[i][j]);
			py = pt->y;
			px = pt->x;
			pt->x = px * (cos(ay) * cos(az)) - py * sin(az) * cos(ay) +
				pt->z * sin(ay);
			pt->y = px * (sin(ax) * sin(ay) * cos(az) + cos(ax) * sin(az)) +
				py * (cos(ax) * cos(az) - sin(ax) * sin(ay) * sin(az)) - pt->z *
				(cos(ay) * sin(ax));
			pt->z = px * (sin(ax) * sin(az) - cos(ax) * cos(az) * sin(ay)) +
				py * (sin(ax) * cos(az) + cos(ax) * sin(ay) * sin(az)) +
				pt->z * cos(ax) * cos(ay);
		}
	}
}
