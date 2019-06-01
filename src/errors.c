/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:32:21 by malluin           #+#    #+#             */
/*   Updated: 2018/12/04 14:57:13 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	usage(char *av)
{
	ft_putstr("usage: ");
	ft_putstr(av);
	ft_putstr(" map file [color_palette]\n");
	exit(42);
}

void	errortoomany(char *av)
{
	ft_putstr("Too many arguments.\n");
	usage(av);
	exit(42);
}

void	error(void)
{
	ft_putstr("Invalid map file.\n");
	exit(42);
}
