/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:23:02 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/16 17:59:53 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_stat;

void	ft_freecontent(void *content)
{
	t_mini	*node;

	node = content;
	ft_free_matrix(&node->full_cmd);
	free(node->full_path);
	if (node->infile != STDIN_FILENO)
		close(node->infile);
	if (node->outfile != STDOUT_FILENO)
		close(node->outfile);
	free(node);
}

static void	*ft_start(t_prompt *p)
{
	int	is_exit;
	int	i;

	is_exit = 0;
	i = ft_lstsize(p->cmds);
	g_stat = exec_proc(p, p->cmds, &is_exit, 0);
	while (i-- > 0)
		waitpid(-1, &g_stat, 0);
	if (!is_exit && g_stat == 13)
		g_stat = 0;
	if (g_stat > 255)
		g_stat = g_stat / 255;
	if (is_exit)
	{
		ft_free_matrix(&p->envp);
		ft_lstclear(&p->cmds, ft_freecontent);
		return (NULL);
	}
	return (p);
}

void	*ft_check_prompt(t_prompt *p)
{
	t_mini	*n;

	p = ft_start(p);
	if (p && p->cmds)
		n = p->cmds->content;
	if (p && p->cmds && n && n->full_cmd && ft_lstsize(p->cmds) == 1)
		p->envp = ft_setenv("_", n->full_cmd[ft_matrixlen(n->full_cmd) - 1], \
			p->envp, 1);
	if (p && p->cmds)
		ft_lstclear(&p->cmds, ft_freecontent);
	return (p);
}
