/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:39:45 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/15 16:39:47 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	k;

	if (!s1 || !s2)
		return (2);
	k = 0;
	while (s1[k] != '\0' && s2[k] != '\0')
	{
		if (((unsigned char *)s1)[k] < ((unsigned char *)s2)[k])
			return (-1);
		if (((unsigned char *)s1)[k] > ((unsigned char *)s2)[k])
			return (1);
		k++;
	}
	return (s1[k] - s2[k]);
}
