/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:52:02 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/16 17:40:08 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_stat;

void	ft_cd_core(t_prompt *p, char *aux, char **str[2])
{
	if (!aux)
		aux = ft_strdup("");
	str[1] = ft_extend_matrix(NULL, aux);
	free(aux);
	aux = getcwd(NULL, 0);
	str[1] = ft_extend_matrix(str[1], aux);
	free(aux);
	ft_cderror(str);
	if (!g_stat)
		p->envp = ft_setenv("OLDPWD", str[1][1], p->envp, 6);
	aux = getcwd(NULL, 0);
	if (!aux)
		aux = ft_strdup("");
	str[1] = ft_extend_matrix(str[1], aux);
	free(aux);
	p->envp = ft_setenv("PWD", str[1][2], p->envp, 3);
	ft_free_matrix(&str[1]);
}

int	ft_cd(t_prompt *p)
{
	char	**str[2];
	char	*aux;

	g_stat = 0;
	str[0] = ((t_mini *)p->cmds->content)->full_cmd;
	if (str[0][2] && (str[0][2][0] != '|' || str[0][2][0] != '>'
			|| str[0][2][0] != '<'))
	{
		printf("minishell: cd: too many arguments\n");
		g_stat = 1;
		return (g_stat);
	}
	aux = ft_getenv("HOME", p->envp, 4);
	ft_cd_core(p, aux, str);
	return (g_stat);
}
