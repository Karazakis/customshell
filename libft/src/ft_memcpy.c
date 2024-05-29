/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:28:00 by dimolin2          #+#    #+#             */
/*   Updated: 2023/02/28 18:28:01 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	k;

	k = 0;
	if (!dest && !src)
		return (dest);
	while (k < n)
	{
		((unsigned char *)dest)[k] = ((unsigned char *)src)[k];
		k++;
	}
	return (dest);
}
