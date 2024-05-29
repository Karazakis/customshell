/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:30:49 by dimolin2          #+#    #+#             */
/*   Updated: 2023/02/28 18:30:51 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	n_len;
	char	*b;

	i = 0;
	b = (char *)big;
	n_len = ft_strlen(little);
	if (n_len == 0 || big == little)
		return (b);
	if (len == 0)
		return (0);
	while (b[i] != '\0' && i < len)
	{
		c = 0;
		while (b[i + c] != '\0' && little[c] != '\0'
			&& b[i + c] == little[c] && i + c < len)
			c++;
		if (c == n_len)
			return (b + i);
		i++;
	}
	return (0);
}
