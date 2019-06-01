/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:07:26 by malluin           #+#    #+#             */
/*   Updated: 2018/12/06 18:56:44 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_key(int key, t_win *mlx)
{
	static float	rot[3] = {0., 0., 0.};

	if (key == 126)
		rot[0] += 0.1;
	else if (key == 125)
		rot[0] -= 0.1;
	else if (key == 123)
		rot[1] += 0.1;
	else if (key == 124)
		rot[1] -= 0.1;
	else if (key == 116)
		rot[2] += 0.1;
	else if (key == 121)
		rot[2] -= 0.1;
	if (key == 15)
	{
		rot[0] = 0;
		rot[1] = 0;
		rot[2] = 0;
	}
	rotate(mlx, rot[0], rot[1], rot[2]);
}

int		deal_key(int key, void *param)
{
	t_win	*mlx;

	mlx = (t_win *)(param);
	if (key == 69)
		mlx->offset_z = mlx->offset_z / 1.1 < 0.3 ? 0.3 : mlx->offset_z / 1.1;
	else if (key == 78)
		mlx->offset_z = mlx->offset_z * 1.1 > 20.0 ? 20.0 : mlx->offset_z * 1.1;
	else if (key == 53)
		exit(1);
	else if (key == 115)
		mlx->scale = mlx->scale + 0.05 > 4 ? 4 : mlx->scale + 0.05;
	else if (key == 119)
		mlx->scale = mlx->scale - 0.05 < 0.5 ? 0.5 : mlx->scale - 0.05;
	else if (key == 15)
	{
		mlx->scale = 1.0;
		mlx->offset_z = 1.0;
	}
	else if (key == 34)
		mlx->iso = mlx->iso == 1 ? 0 : 1;
	refresh_init(mlx);
	rotate_key(key, mlx);
	refresh_show(mlx);
	return (0);
}
