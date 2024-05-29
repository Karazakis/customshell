/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:24:34 by dimolin2          #+#    #+#             */
/*   Updated: 2023/08/17 15:11:38 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*cmem;
	size_t	k;
	size_t	tot_size;

	k = 0;
	if (!nmemb || !size)
		return (NULL);
	tot_size = nmemb * size;
	cmem = (char *) malloc(tot_size);
	if (!cmem)
		return (NULL);
	while (k < tot_size)
		cmem[k++] = '\0';
	return (cmem);
}
