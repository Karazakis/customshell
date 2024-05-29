/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_path_extend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:50:45 by dimolin2          #+#    #+#             */
/*   Updated: 2023/08/16 18:04:18 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_stat;

char	*ft_expandpath(char *str, int i, int qt[2], char *var)
{
	char	*path;
	char	*aux;

	qt[0] = 0;
	qt[1] = 0;
	while (str && str[++i])
	{
		qt[0] = (qt[0] + (!qt[1] && str[i] == '\'')) % 2;
		qt[1] = (qt[1] + (!qt[0] && str[i] == '\"')) % 2;
		if (!qt[0] && !qt[1] && str[i] == '~' && (i == 0 || \
			str[i - 1] != '$'))
		{
			aux = ft_substr(str, 0, i);
			path = ft_strjoin(aux, var);
			free(aux);
			aux = ft_substr(str, i + 1, ft_strlen(str));
			free(str);
			str = ft_strjoin(path, aux);
			free(aux);
			free(path);
			return (ft_expandpath(str, i + ft_strlen(var) - 1, qt, var));
		}
	}
	free(var);
	return (str);
}

static char	*ft_get_substr_var(char *str, int i, t_prompt *prompt)
{
	char	*aux;
	int		pos;
	char	*path;
	char	*var;

	pos = ft_strchars_i(&str[i], "|\"\'$?>< ") + (ft_strchr("$?", str[i]) != 0);
	if (pos == -1)
		pos = ft_strlen(str) - 1;
	aux = ft_substr(str, 0, i - 1);
	var = ft_getenv(&str[i], prompt->envp, \
		ft_strchars_i(&str[i], "\"\'$|>< "));
	if (!var && str[i] == '$')
		var = ft_itoa(prompt->pid);
	else if (!var && str[i] == '?')
		var = ft_itoa(g_stat);
	path = ft_strjoin(aux, var);
	free(aux);
	aux = ft_strjoin(path, &str[i + pos]);
	free(var);
	free(path);
	free(str);
	return (aux);
}

char	*ft_expndvar(char *str, int i, int qt[2], t_prompt *prompt)
{
	qt[0] = 0;
	qt[1] = 0;
	while (str && str[++i])
	{
		qt[0] = (qt[0] + (!qt[1] && str[i] == '\'')) % 2;
		qt[1] = (qt[1] + (!qt[0] && str[i] == '\"')) % 2;
		if (!qt[0] && str[i] == '$' && str[i + 1] && \
			((ft_strchars_i(&str[i + 1], "/~%^{}:; ") && !qt[1]) || \
			(ft_strchars_i(&str[i + 1], "/~%^{}:;\"") && qt[1])))
			return (ft_expndvar(ft_get_substr_var(str, ++i, prompt), -1, \
				qt, prompt));
	}
	return (str);
}
