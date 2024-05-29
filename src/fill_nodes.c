/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:37:38 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/16 19:23:12 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int		g_stat;

static t_mini	*get_params(t_mini *node, char **a[2], int *i)
{
	if (a[0][*i])
	{
		if (a[0][*i][0] == '>' && a[0][*i][1] && a[0][*i][1] == '>')
			node = ft_get_out2(node, a[1], i);
		else if (a[0][*i][0] == '>' && a[0][*i][1] == '\0')
			node = ft_get_out1(node, a[1], i);
		else if (a[0][*i][0] == '<' && a[0][*i][1] && a[0][*i][1] == '<')
			node = ft_get_in2(node, a[1], i);
		else if (a[0][*i][0] == '<' && a[0][*i][1] == '\0')
			node = ft_get_in1(node, a[1], i);
		else if (a[0][*i][0] != '|')
			node->full_cmd = ft_extend_matrix(node->full_cmd, a[1][*i]);
		else
		{
			ft_perror(PIPENDERR, NULL, 2);
			*i = -2;
		}
		return (node);
	}
	ft_perror(PIPENDERR, NULL, 2);
	*i = -2;
	return (node);
}

static t_list	*stop_fill(t_list *cmds, char **args, char **temp)
{
	ft_lstclear(&cmds, ft_freecontent);
	ft_free_matrix(&args);
	ft_free_matrix(&temp);
	(void)args;
	return (NULL);
}

t_list	*ft_take_cmd(char **args, char **pargs, int i)
{
	t_list	*cmds[2];
	char	**temp[2];

	cmds[0] = NULL;
	temp[1] = args;
	while (args[++i])
	{
		cmds[1] = ft_lstlast(cmds[0]);
		if (i == 0 || (args[i][0] == '|' && args[i + 1] && args[i + 1][0]))
		{
			i += args[i][0] == '|';
			ft_lstadd_back(&cmds[0], ft_lstnew(ft_init()));
			cmds[1] = ft_lstlast(cmds[0]);
		}
		temp[0] = pargs;
		cmds[1]->content = get_params(cmds[1]->content, temp, &i);
		if (i < 0)
			return (stop_fill(cmds[0], pargs, args));
		if (!args[i])
			break ;
	}
	ft_free_matrix(&pargs);
	ft_free_matrix(&args);
	return (cmds[0]);
}
