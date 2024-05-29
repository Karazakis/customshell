/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:29:49 by dimolin2          #+#    #+#             */
/*   Updated: 2023/08/15 16:38:38 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*j_str;
	size_t	i;
	size_t	k;

	if (!s1)
		return (s2);
	j_str = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1),
			sizeof(char));
	if (!j_str)
		return (NULL);
	i = 0;
	k = 0;
	while (s1 && s1[k])
		j_str[i++] = s1[k++];
	if (s1 != NULL)
		free(s1);
	k = 0;
	while (s2 && s2[k])
		j_str[i++] = s2[k++];
	if (s2[0] != '=')
		free(s2);
	return (j_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*j_str;
	size_t	i;

	if (!s2)
		return (NULL);
	j_str = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (j_str == NULL)
		return (NULL);
	i = 0;
	while (s1 && *s1)
		j_str[i++] = *s1++;
	while (s2 && *s2)
		j_str[i++] = *s2++;
	j_str[i] = '\0';
	return (j_str);
}
