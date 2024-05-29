/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:24:12 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/19 14:12:12 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_stat;

int	ft_putmatrix_special_fd(char **m, int nl, int fd)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (m && m[i])
	{
		if (nl)
		{
			ft_putstr_fd("declare -x ", fd);
			count += ft_putendl_fd(m[i], fd);
		}
		else
			count += ft_putstr_fd(m[i], fd);
		i++;
	}
	return (count);
}

int	ft_export_check(t_list *cmd, char **a, int n)
{
	if (!cmd->next && a && ft_matrixlen(a) >= 2 && !ft_strncmp(*a, "export", n)
		&& n == 6)
		return (1);
	return (0);
}

void	ft_export_core(int *ij, t_prompt *prompt, char **av)
{
	int	pos;

	ij[0] = 1;
	while (av[ij[0]])
	{
		if (av[ij[0]][0] == '=' || ft_isdigit(av[ij[0]][0]))
		{
			printf("minishell: export: `%s': not a valid identifier\n",
				av[ij[0]]);
			return ;
		}
		pos = var_in_envp(av[ij[0]], prompt->envp, ij);
		if (pos == 1)
		{
			free(prompt->envp[ij[1]]);
			prompt->envp[ij[1]] = ft_strdup(av[ij[0]]);
		}
		else if (!pos)
			prompt->envp = ft_extend_matrix(prompt->envp, av[ij[0]]);
		ij[0]++;
	}
}

int	ft_export(t_prompt *prompt)
{
	int		ij[2];
	char	**av;

	av = ((t_mini *)prompt->cmds->content)->full_cmd;
	if (ft_matrixlen(av) >= 2)
		ft_export_core(ij, prompt, av);
	else
		ft_print_ordered_env(prompt->envp, ij);
	return (0);
}
