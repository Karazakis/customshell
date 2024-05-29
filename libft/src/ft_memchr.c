/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:27:41 by dimolin2          #+#    #+#             */
/*   Updated: 2023/02/28 18:27:42 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	k;
	char	*t;

	k = 0;
	t = (void *)s;
	while (k < n)
	{
		if ((char)c == t[k])
			return (&t[k]);
		k++;
	}
	return (NULL);
}
