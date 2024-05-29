/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:30:06 by dimolin2          #+#    #+#             */
/*   Updated: 2023/02/28 18:30:08 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	k;

	k = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (k < size - 1 && src[k] != '\0')
	{
		dst[k] = src[k];
		k++;
	}
	dst[k] = '\0';
	return (ft_strlen(src));
}
