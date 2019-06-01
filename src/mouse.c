/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:43:49 by malluin           #+#    #+#             */
/*   Updated: 2018/12/04 12:14:39 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mxline(t_win *mlx, t_pix px1, t_pix px2, int color)
{
	int dx;
	int dy;
	int e;
	int signe;

	if (px1.u > px2.u)
	{
		ft_swap(&px1.u, &px2.u);
		ft_swap(&px1.v, &px2.v);
	}
	signe = px2.v >= px1.v ? 1 : -1;
	dy = (px2.v - px1.v);
	dx = px2.u - px1.u;
	e = (dy - dx * signe);
	while (px1.u <= px2.u)
	{
		place_pixel(mlx, px1.u, px1.v, color);
		px1.u++;
		e = e + dy;
		if ((signe == 1 && e >= 0) || (signe == -1 && e <= 0))
		{
			px1.v += signe;
			e -= dx * signe;
		}
	}
}

void	myline(t_win *mlx, t_pix px1, t_pix px2, int color)
{
	int dx;
	int dy;
	int e;
	int signe;

	if (px1.v > px2.v)
	{
		ft_swap(&px1.u, &px2.u);
		ft_swap(&px1.v, &px2.v);
	}
	signe = px2.u >= px1.u ? 1 : -1;
	dy = (px2.v - px1.v);
	dx = px2.u - px1.u;
	e = (dx - dy * signe);
	while (px1.v <= px2.v)
	{
		place_pixel(mlx, px1.u, px1.v, color);
		px1.v++;
		e = e + dx;
		if ((signe == 1 && e >= 0) || (signe == -1 && e <= 0))
		{
			px1.u += signe;
			e -= dy * signe;
		}
	}
}

int		mouse_line(int button, int x, int y, void *param)
{
	static int		place = 0;
	static t_pix	px1;
	t_pix			px2;
	t_win			*mlx;

	mlx = (t_win *)param;
	if (place == 0 && button < 90000)
	{
		px1.u = x;
		px1.v = y;
		place = 1;
	}
	else
	{
		px2.u = x;
		px2.v = y;
		if (ft_iabs(px2.u - px1.u) > ft_iabs(px2.v - px1.v))
			mxline(mlx, px1, px2, rgb(0, 255, 255));
		else
			myline(mlx, px1, px2, rgb(0, 255, 255));
		place = 0;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->image_ptr, 0, 0);
	}
	return (!place);
}
