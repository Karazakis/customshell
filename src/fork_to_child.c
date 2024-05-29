/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_to_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:28:48 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/16 17:59:36 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_stat;

int	ft_is_builtin(t_mini *n)
{
	int	l;

	if (!n->full_cmd)
		return (0);
	if ((n->full_cmd && ft_strchr(*n->full_cmd, '/')) || (n->full_path
			&& ft_strchr(n->full_path, '/')))
		return (0);
	l = ft_strlen(*n->full_cmd);
	if (!ft_strncmp(*n->full_cmd, "pwd", l) && l == 3)
		return (1);
	if (!ft_strncmp(*n->full_cmd, "env", l) && l == 3)
		return (1);
	if (!ft_strncmp(*n->full_cmd, "cd", l) && l == 2)
		return (1);
	if (!ft_strncmp(*n->full_cmd, "export", l) && l == 6)
		return (1);
	if (!ft_strncmp(*n->full_cmd, "unset", l) && l == 5)
		return (1);
	if (!ft_strncmp(*n->full_cmd, "echo", l) && l == 4)
		return (1);
	if (!ft_strncmp(*n->full_cmd, "exit", l) && l == 4)
		return (1);
	return (0);
}

void	*ft_redir(t_list *cmd, int fd[2])
{
	t_mini	*node;

	node = cmd->content;
	if (node->infile != STDIN_FILENO)
	{
		if (dup2(node->infile, STDIN_FILENO) == -1)
			return (ft_perror(DUPERR, NULL, 1));
		close(node->infile);
	}
	if (node->outfile != STDOUT_FILENO)
	{
		if (dup2(node->outfile, STDOUT_FILENO) == -1)
			return (ft_perror(DUPERR, NULL, 1));
		close(node->outfile);
	}
	else if (cmd->next && dup2(fd[WRITE_END], STDOUT_FILENO) == -1)
		return (ft_perror(DUPERR, NULL, 1));
	close(fd[WRITE_END]);
	return ("");
}

void	ft_builtin(t_prompt *prompt, t_mini *n, int l, t_list *cmd)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (!ft_is_builtin(n) && n->full_cmd)
		execve(n->full_path, n->full_cmd, prompt->envp);
	else if (n->full_cmd && !ft_strncmp(*n->full_cmd, "pwd", l) && l == 3)
		g_stat = ft_pwd();
	else if (ft_is_builtin(n) && n->full_cmd && !ft_strncmp(*n->full_cmd,
			"echo", l) && l == 4)
		g_stat = ft_echo(cmd);
	else if (ft_is_builtin(n) && n->full_cmd && !ft_strncmp(*n->full_cmd,
			"export", l) && l == 6)
		g_stat = ft_export(prompt);
	else if (ft_is_builtin(n) && n->full_cmd && !ft_strncmp(*n->full_cmd, "env",
			l) && l == 3)
	{
		ft_putmatrix_fd(prompt->envp, 1, 1);
		g_stat = 0;
	}
}

void	*ft_child(t_prompt *prompt, t_list *cmd, int fd[2])
{
	t_mini	*n;
	int		l;

	n = cmd->content;
	l = 0;
	if (n->full_cmd)
		l = ft_strlen(*n->full_cmd);
	ft_redir(cmd, fd);
	ft_builtin(prompt, n, l, cmd);
	close(fd[READ_END]);
	ft_lstclear(&prompt->cmds, ft_freecontent);
	exit(g_stat);
}

void	ft_fork(t_prompt *prompt, t_list *cmd, int fd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		close(fd[READ_END]);
		close(fd[WRITE_END]);
		ft_perror(FORKERR, NULL, 1);
	}
	else if (!pid)
		ft_child(prompt, cmd, fd);
}
