/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:29:32 by dimolin2          #+#    #+#             */
/*   Updated: 2023/02/28 18:29:33 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*t;
	size_t	siz_s;

	siz_s = ft_strlen(s) + 1;
	t = (char *) malloc(siz_s * sizeof(char));
	if (t == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(t, s, siz_s);
	return (t);
}
