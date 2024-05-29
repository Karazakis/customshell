/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:37:51 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/15 16:38:10 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	k;

	k = 0;
	if (!s1 || !s2)
		return (2);
	while (k < n && (s1[k] != '\0' || s2[k] != '\0'))
	{
		if (((unsigned char *)s1)[k] < ((unsigned char *)s2)[k])
			return (-1);
		if (((unsigned char *)s1)[k] > ((unsigned char *)s2)[k])
			return (1);
		k++;
	}
	return (0);
}
