/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlist2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:19:31 by diego             #+#    #+#             */
/*   Updated: 2023/08/17 15:11:38 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	intlist_get_average(t_intl **list)
{
	t_intl	*tmp;
	int		sum;
	int		res;

	tmp = *list;
	sum = 0;
	res = 0;
	while (tmp)
	{
		sum += tmp->content;
		res++;
		tmp = tmp->next;
	}
	return (sum / res);
}

t_intl	*intlist_lastnode(t_intl **list)
{
	t_intl	*tmp;

	tmp = (*list);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

t_intl	*intlist_new(int n)
{
	t_intl	*new_one;

	new_one = (t_intl *)malloc(sizeof(t_intl));
	if (!new_one)
		return (NULL);
	new_one->content = n;
	new_one->next = NULL;
	return (new_one);
}

int	intlist_dub_smallest(t_intl **list_a, t_intl **list_b)
{
	t_intl	*tmp;
	int		smallest;

	tmp = (*list_a);
	smallest = tmp->content;
	while (tmp)
	{
		if (tmp->content < smallest)
			smallest = tmp->content;
		tmp = tmp->next;
	}
	tmp = (*list_b);
	while (tmp)
	{
		if (tmp->content < smallest)
			smallest = tmp->content;
		tmp = tmp->next;
	}
	return (smallest);
}

int	intlist_ordered_reverse(t_intl **list)
{
	t_intl	*tmp;

	tmp = (*list);
	while (tmp->next != NULL)
	{
		if (tmp->content < tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
