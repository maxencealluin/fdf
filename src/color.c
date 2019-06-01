/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:53:56 by malluin           #+#    #+#             */
/*   Updated: 2018/12/04 16:04:48 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		lin_interx(t_pix px1, t_pix px2, int x, int swap)
{
	double	ratio;
	int		rgb[3];
	int		c1;
	int		c2;

	c1 = px1.ptr->color;
	c2 = px2.ptr->color;
	if (swap == 1)
		ft_swap(&c1, &c2);
	ratio = percent(px1.u, px2.u, x);
	rgb[0] = get_light((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, ratio);
	rgb[1] = get_light((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, ratio);
	rgb[2] = get_light(c1 & 0xFF, c2 & 0xFF, ratio);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

int		lin_intery(t_pix px1, t_pix px2, int y, int swap)
{
	double	ratio;
	int		rgb[3];
	int		c1;
	int		c2;

	c1 = px1.ptr->color;
	c2 = px2.ptr->color;
	if (swap == 1)
		ft_swap(&c1, &c2);
	ratio = percent(px1.v, px2.v, y);
	rgb[0] = get_light((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, ratio);
	rgb[1] = get_light((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, ratio);
	rgb[2] = get_light(c1 & 0xFF, c2 & 0xFF, ratio);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}
