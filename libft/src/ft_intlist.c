/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:35:04 by dimolin2          #+#    #+#             */
/*   Updated: 2023/08/17 15:11:38 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_intl	*intlist_push(int content)
{
	t_intl	*new;

	new = (t_intl *)malloc(sizeof(t_intl));
	new->content = content;
	new->next = NULL;
	return (new);
	free(new);
}

int	intlist_lenght(t_intl **list)
{
	t_intl	*tmp;
	int		n;

	tmp = (*list);
	n = 1;
	while (tmp->next)
	{
		tmp = tmp->next;
		n++;
	}
	return (n);
}

int	intlist_biggest(t_intl **list)
{
	t_intl	*tmp;
	int		n;

	tmp = (*list);
	n = tmp->content;
	while (tmp)
	{
		if (tmp->content > n)
			n = tmp->content;
		tmp = tmp->next;
	}
	return (n);
}

int	intlist_smallest(t_intl **list)
{
	t_intl	*tmp;
	int		n;

	tmp = (*list);
	n = tmp->content;
	while (tmp)
	{
		if (tmp->content < n)
			n = tmp->content;
		tmp = tmp->next;
	}
	return (n);
}

int	intlist_ordered(t_intl	**list)
{
	t_intl	*tmp;

	tmp = (*list);
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
