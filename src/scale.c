/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:59:49 by malluin           #+#    #+#             */
/*   Updated: 2018/12/06 17:43:49 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	scale(t_win *mlx, float coef)
{
	int		i;
	int		j;
	float	xgap;
	float	ygap;
	t_coord	*coord;

	xgap = ft_fmax((float)(HEIGHT / (float)mlx->map->size_x * 2 / 3)
	* coef, 1.0);
	ygap = ft_fmax((float)(HEIGHT / (float)mlx->map->size_y * 2 / 3)
	* coef, 1.0);
	i = 0;
	while (i < mlx->map->size_y)
	{
		j = 0;
		while (j < mlx->map->size_x)
		{
			coord = &(mlx->proj[i][j]);
			coord->x *= xgap;
			coord->y *= ygap;
			coord->z *= coef / ft_fmax(0.1, (float)(mlx->map->high->z -
				mlx->map->low->z) / ft_fmax((float)mlx->map->size_x, 1.0));
			j++;
		}
		i++;
	}
}

void	offset_z(t_win *mlx, float offset)
{
	int		i;
	int		j;
	t_coord	*coord;

	i = 0;
	while (i < mlx->map->size_y)
	{
		j = 0;
		while (j < mlx->map->size_x)
		{
			coord = &(mlx->proj[i][j]);
			coord->z /= offset;
			j++;
		}
		i++;
	}
}
