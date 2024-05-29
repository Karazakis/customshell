/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:45:55 by dimolin2          #+#    #+#             */
/*   Updated: 2023/08/17 15:08:44 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	k;

	k = 0;
	if (!str || !(*str))
		return (0);
	while (str[k] != 0)
		k++;
	return (k);
}

ssize_t	ft_get_line_size(char *buff_read)
{
	ssize_t	k;

	k = 0;
	if (!buff_read)
		return (0);
	while (buff_read[k] != '\0')
	{
		if (buff_read[k] == '\n')
			return (++k);
		k++;
	}
	return (k);
}

int	ft_search_bsn(char *buff_read)
{
	if (!buff_read)
		return (0);
	while (*buff_read)
	{
		if (*buff_read == '\n')
			return (1);
		buff_read++;
	}
	return (0);
}

void	*ft_free_null(char **read)
{
	if (!*read)
		return (NULL);
	free(*read);
	*read = NULL;
	return (NULL);
}
