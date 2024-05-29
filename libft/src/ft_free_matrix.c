/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:24:54 by dimolin2          #+#    #+#             */
/*   Updated: 2023/08/04 13:45:01 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix(char ***m)
{
	int	i;

	i = 0;
	while (m && m[0] && m[0][i])
	{
		free(m[0][i]);
		i++;
	}
	if (m)
	{
		free(m[0]);
		*m = NULL;
	}
}

char	*ft_free_matrix_xy(char ***matrix, int x, int y)
{
	if (!*matrix)
		return (NULL);
	(void) x;
	while (y--)
	{
		ft_free_null((char **) &((*matrix)[y]));
	}
	free(*matrix);
	return (NULL);
}

/* for free gnl */
char	*ft_free_matrix_nomat(char **matrix, int i)
{
	while (i)
		ft_free_null(&(matrix)[i--]);
	return (NULL);
}
