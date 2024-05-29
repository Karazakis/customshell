/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:29:03 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/17 16:55:06 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_stat;

void	*ft_check_and_fork(t_prompt *prompt, t_list *cmd, int fd[2])
{
	t_mini	*nod;
	DIR		*dr;

	nod = cmd->content;
	dr = NULL;
	if (nod->full_cmd)
		dr = opendir(*nod->full_cmd);
	if (nod->infile == -1 || nod->outfile == -1)
		return (NULL);
	if ((nod->full_path && access(nod->full_path, X_OK) == 0)
		|| ft_is_builtin(nod))
		ft_fork(prompt, cmd, fd);
	else if (!ft_is_builtin(nod) && ((nod->full_path && !access(nod->full_path,
					F_OK)) || dr))
		g_stat = 126;
	else if (!ft_is_builtin(nod) && nod->full_cmd)
		g_stat = 1;
	if (dr)
		closedir(dr);
	return ("");
}

static DIR	*ft_cmd_checks(t_prompt *prompt, t_list *cmd, char ***s, char *path)
{
	t_mini	*nod;
	DIR		*dr;

	dr = NULL;
	nod = cmd->content;
	if (nod && nod->full_cmd)
		dr = opendir(*nod->full_cmd);
	if (nod && nod->full_cmd && ft_strchr(*nod->full_cmd, '/') && !dr)
	{
		*s = ft_split(*nod->full_cmd, '/');
		nod->full_path = ft_strdup(*nod->full_cmd);
		free(nod->full_cmd[0]);
		nod->full_cmd[0] = ft_strdup(s[0][ft_matrixlen(*s) - 1]);
	}
	else if (!ft_is_builtin(nod) && nod && nod->full_cmd && !dr)
	{
		path = ft_getenv("PATH", prompt->envp, 4);
		*s = ft_split(path, ':');
		free(path);
		nod->full_path = ft_findcmd(*s, *nod->full_cmd, nod->full_path);
		if (!nod->full_path || !nod->full_cmd[0] || !nod->full_cmd[0][0])
			ft_perror(NCMD, *nod->full_cmd, 127);
	}
	return (dr);
}

void	ft_cmd_get(t_prompt *prompt, t_list *cmd, char **s, char *path)
{
	t_mini	*nod;
	DIR		*dr;

	nod = cmd->content;
	dr = ft_cmd_checks(prompt, cmd, &s, path);
	if (!ft_is_builtin(nod) && nod && nod->full_cmd && dr)
		ft_perror(IS_DIR, *nod->full_cmd, 126);
	else if (!ft_is_builtin(nod) && nod && nod->full_path
		&& access(nod->full_path, F_OK) == -1)
		ft_perror(NDIR, nod->full_path, 127);
	else if (!ft_is_builtin(nod) && nod && nod->full_path
		&& access(nod->full_path, X_OK) == -1)
		ft_perror(NPERM, nod->full_path, 126);
	if (dr)
		closedir(dr);
	ft_free_matrix(&s);
}

void	*ft_cmd_exec(t_prompt *prompt, t_list *cmd)
{
	int	fd[2];

	ft_cmd_get(prompt, cmd, NULL, NULL);
	if (pipe(fd) == -1)
		return (ft_perror(PIPERR, NULL, 1));
	if (!ft_check_and_fork(prompt, cmd, fd))
		return (NULL);
	close(fd[WRITE_END]);
	if (cmd->next && !((t_mini *)cmd->next->content)->infile)
		((t_mini *)cmd->next->content)->infile = fd[READ_END];
	else
		close(fd[READ_END]);
	if (((t_mini *)cmd->content)->infile > 2)
		close(((t_mini *)cmd->content)->infile);
	if (((t_mini *)cmd->content)->outfile > 2)
		close(((t_mini *)cmd->content)->outfile);
	return (NULL);
}

int	exec_proc(t_prompt *prompt, t_list *cmd, int *is_exit, int nod)
{
	char	**a;

	while (cmd)
	{
		a = ((t_mini *)cmd->content)->full_cmd;
		nod = 0;
		if (a)
			nod = ft_strlen(*a);
		if (a && !ft_strncmp(*a, "exit", nod) && nod == 4)
			g_stat = ft_exit(cmd, is_exit);
		else if (!cmd->next && a && !ft_strncmp(*a, "cd", nod) && nod == 2)
			g_stat = ft_cd(prompt);
		else if (!cmd->next && a && !ft_strncmp(*a, "unset", nod) && nod == 5)
			g_stat = ft_unset(prompt);
		else if (ft_export_check(cmd, a, nod) == 1)
			g_stat = ft_export(prompt);
		else
		{
			signal(SIGINT, SIG_IGN);
			signal(SIGQUIT, SIG_IGN);
			ft_cmd_exec(prompt, cmd);
		}
		cmd = cmd->next;
	}
	return (g_stat);
}
