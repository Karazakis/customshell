/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:30:26 by dimolin2          #+#    #+#             */
/*   Updated: 2023/02/28 18:30:27 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	size_t	k;

	if (!s)
		return (NULL);
	k = 0;
	new_str = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s[k] != '\0')
	{
		new_str[k] = (*f)(k, s[k]);
		k++;
	}
	new_str[k] = '\0';
	return (new_str);
}
