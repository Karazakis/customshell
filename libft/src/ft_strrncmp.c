/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:36:54 by dimolin2          #+#    #+#             */
/*   Updated: 2023/03/01 18:36:55 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrncmp(char *s1, char *s2, int n)
{
	int	len_x;
	int	len_y;
	int	i;

	len_x = ft_strlen(s1) - 1;
	len_y = ft_strlen(s2) - 1;
	i = 0;
	while (i < n)
	{
		if (s1[len_x] == s2[len_y])
		{
			len_y--;
			len_x--;
			i++;
		}
		else
			return (s1[len_x] - s2[len_y]);
	}
	return (0);
}
