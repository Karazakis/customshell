/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:24:16 by dimolin2          #+#    #+#             */
/*   Updated: 2023/08/17 15:11:38 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_give_spot(char c, char *base_max, char *base_min)
{
	int	i;

	i = 0;
	while (base_min[i])
	{
		if (base_min[i] == c || base_max[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_hex(char *str)
{
	int	atoi;
	int	i;

	i = 2;
	if (!str)
		return (0);
	atoi = 0;
	while (str[i] && str[i] != '\n' && str[i] != 32)
	{
		atoi = atoi * 16 + ft_give_spot(str[i], "0123456789ABCDEF",
				"0123456789abcdef");
		i++;
	}
	return (atoi);
}
