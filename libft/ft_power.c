/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:52:21 by malluin           #+#    #+#             */
/*   Updated: 2018/11/30 14:53:54 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	return (nb * ft_power(nb, power - 1));
}
