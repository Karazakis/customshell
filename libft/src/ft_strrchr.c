/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:30:58 by dimolin2          #+#    #+#             */
/*   Updated: 2023/02/28 18:31:00 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	k;

	k = ft_strlen(s);
	while (k > 0)
	{
		if (s[k] == c)
			return ((char *)&s[k]);
		k--;
	}
	if (s[0] == c)
		return ((char *)&s[0]);
	return (NULL);
}
