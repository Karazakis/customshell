/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:57:00 by dimolin2          #+#    #+#             */
/*   Updated: 2023/08/16 15:48:42 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_size_word(char const *s, char c, size_t k)
{
	size_t	len;

	len = 0;
	while (s[k + len] != c && s[k + len] != '\0')
		len++;
	return (len);
}

size_t	ft_count_words(char const *s, char c)
{
	size_t	k;
	size_t	words;
	size_t	hold;

	k = 0;
	words = 1;
	hold = 1;
	while (s[k] != '\0')
	{
		if (hold && s[k] == c)
		{
			hold = 0;
			words++;
		}
		else if (s[k] != c)
			hold = 1;
		k++;
	}
	if (hold == 0)
		words--;
	return (words + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**str_matx;
	size_t	k[2];
	size_t	w_size;

	k[0] = 0;
	k[1] = 0;
	w_size = 0;
	if (!s)
		return (NULL);
	str_matx = (char **)ft_calloc(ft_count_words(s, c), sizeof(char *));
	if (!str_matx || !s)
		return (NULL);
	while (s[k[0]] != '\0')
	{
		if (s[k[0]] == c)
			k[0]++;
		else
		{
			w_size = ft_size_word(s, c, k[0]);
			str_matx[k[1]++] = ft_substr(s, k[0], w_size);
			k[0] += w_size;
		}
	}
	str_matx[k[1]] = NULL;
	return (str_matx);
}
