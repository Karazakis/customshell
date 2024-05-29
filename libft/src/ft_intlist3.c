/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlist3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:48:56 by dimolin2          #+#    #+#             */
/*   Updated: 2023/08/17 15:11:38 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	intlist_delone(t_intl **st_n)
{
	t_intl	*tmp;

	tmp = *st_n;
	(*st_n) = (*st_n)->next;
	free(tmp);
}

void	intlist_clear(t_intl **st_n)
{
	t_intl	*tmp;

	tmp = NULL;
	while (*st_n)
	{
		tmp = (*st_n)->next;
		free(*st_n);
		(*st_n) = tmp;
	}
}
