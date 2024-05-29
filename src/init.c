/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:23:16 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/16 17:55:19 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_stat;

void	ft_getpid(t_prompt *p)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_perror(FORKERR, NULL, 1);
		ft_free_matrix(&p->envp);
		exit(1);
	}
	if (!pid)
	{
		ft_free_matrix(&p->envp);
		exit(1);
	}
	waitpid(pid, NULL, 0);
	p->pid = pid - 1;
}

t_prompt	ft_initvars(t_prompt prompt, char *str, char **av)
{
	char	*num;

	str = getcwd(NULL, 0);
	prompt.envp = ft_setenv("PWD", str, prompt.envp, 3);
	free(str);
	str = ft_getenv("SHLVL", prompt.envp, 5);
	if (!str || ft_atoi(str) <= 0)
		num = ft_strdup("1");
	else
		num = ft_itoa(ft_atoi(str) + 1);
	free(str);
	prompt.envp = ft_setenv("SHLVL", num, prompt.envp, 5);
	free(num);
	str = ft_getenv("PATH", prompt.envp, 4);
	if (!str)
		prompt.envp = ft_setenv("PATH",
				"/usr/local/sbin:/usr/local/bin:/usr/bin:/bin", prompt.envp, 4);
	free(str);
	str = ft_getenv("_", prompt.envp, 1);
	if (!str)
		prompt.envp = ft_setenv("_", av[0], prompt.envp, 1);
	free(str);
	return (prompt);
}

t_prompt	ft_prompt(char **av, char **envp)
{
	t_prompt	prompt;
	char		*str;

	str = NULL;
	prompt.cmds = NULL;
	prompt.envp = ft_dup_matrix(envp);
	g_stat = 0;
	ft_getpid(&prompt);
	prompt = ft_initvars(prompt, str, av);
	return (prompt);
}
