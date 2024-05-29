/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:22:31 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/16 18:00:32 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	var_in_envp2(char *av, char **envp, int *j)
{
	int	pos;

	*j = 1;
	pos = ft_strchr_i(av, '=');
	if (pos == -1)
		return (-1);
	while (envp[*j])
	{
		if (!ft_strncmp(envp[*j], av, pos + 1))
			return (1);
		*j += 1;
	}
	return (0);
}

int	ft_unset(t_prompt *prompt)
{
	char	**av;
	int		i;
	int		j;

	i = 0;
	av = ((t_mini *)prompt->cmds->content)->full_cmd;
	if (ft_matrixlen(av) >= 2)
	{
		while (av[++i])
		{
			j = -1;
			while (av[i][++j])
			{
				if (av[i][j] == '=' || ft_isdigit(av[i][0]))
				{
					printf("bash: unset: `%s': not a valid identifier\n", av[i]);
					return (0);
				}
			}
			av[i] = ft_strjoin_free(av[i], "=");
			if (var_in_envp2(av[i], prompt->envp, &j))
				ft_matrix_replace_in(&prompt->envp, NULL, j);
		}
	}
	return (0);
}
