/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:39:23 by malluin           #+#    #+#             */
/*   Updated: 2018/12/04 16:18:41 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	xline(t_win *mlx, t_pix px1, t_pix px2)
{
	t_der der;

	der.swap = 0;
	if (px1.u > px2.u)
	{
		ft_swap(&px1.u, &px2.u);
		ft_swap(&px1.v, &px2.v);
		der.swap = 1;
	}
	der.signe = px2.v >= px1.v ? 1 : -1;
	der.dy = (px2.v - px1.v);
	der.dx = px2.u - px1.u;
	der.e = (der.dy - der.dx * der.signe);
	der.or = px1.u;
	while (der.or <= px2.u)
	{
		place_pixel(mlx, der.or, px1.v, lin_interx(px1, px2, der.or, der.swap));
		der.or++;
		der.e = der.e + der.dy;
		if ((der.signe == 1 && der.e >= 0) || (der.signe == -1 && der.e <= 0))
		{
			px1.v += der.signe;
			der.e -= der.dx * der.signe;
		}
	}
}

void	yline(t_win *mlx, t_pix px1, t_pix px2)
{
	t_der der;

	der.swap = 0;
	if (px1.v > px2.v)
	{
		ft_swap(&px1.u, &px2.u);
		ft_swap(&px1.v, &px2.v);
		der.swap = 1;
	}
	der.signe = px2.u >= px1.u ? 1 : -1;
	der.dy = (px2.v - px1.v);
	der.dx = px2.u - px1.u;
	der.e = (der.dx - der.dy * der.signe);
	der.or = px1.v;
	while (der.or <= px2.v)
	{
		place_pixel(mlx, px1.u, der.or, lin_intery(px1, px2, der.or, der.swap));
		der.or++;
		der.e = der.e + der.dx;
		if ((der.signe == 1 && der.e >= 0) || (der.signe == -1 && der.e <= 0))
		{
			px1.u += der.signe;
			der.e -= der.dy * der.signe;
		}
	}
}

void	place_line(t_win *param, t_pix px, t_pix px1)
{
	if (ft_iabs(px.u - px1.u) > ft_iabs(px.v - px1.v))
		xline((t_win *)param, px, px1);
	else
		yline((t_win *)param, px, px1);
}
