/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:19:56 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/17 16:25:39 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_wlen_check(char *prompt, int *i, int *wlen)
{
	if (prompt[i[0]] == '"' || prompt[i[0]] == 39)
	{
		*wlen += 1;
		while (prompt[i[0] + 1] && prompt[i[0] + 1] != '"' && prompt[i[0]
				+ 1] != 39)
		{
			*wlen += 1;
			i[0]++;
		}
	}
}

int	ft_strlen_special(char *str)
{
	int	i;
	int	flg;
	int	len;

	i = 0;
	flg = 0;
	len = 0;
	while (str[i])
	{
		if ((str[i] == '"' && flg == 0) || (str[i] == 39 && flg == 0))
		{
			if (str[i] == '"')
				flg = 1;
			else
				flg = 2;
		}
		else if ((str[i] == '"' && flg == 1) || (str[i] == 39 && flg == 2))
			flg = 0;
		else
			len++;
		i++;
	}
	return (len);
}

char	*ft_split_trim_core(char **res, char **s, int i)
{
	int	flg;
	int	j;
	int	k;

	flg = 0;
	j = 0;
	k = 0;
	while (s[i][j])
	{
		if ((s[i][j] == '"' && flg == 0) || (s[i][j] == 39 && flg == 0))
		{
			if (s[i][j] == '"')
				flg = 1;
			else
				flg = 2;
		}
		else if ((s[i][j] == '"' && flg == 1) || (s[i][j] == 39 && flg == 2))
			flg = 0;
		else
			res[i][k++] = s[i][j];
		j++;
	}
	return (res[i]);
}

char	**ft_split_trim(char **s, t_prompt *prompt)
{
	int		i;
	int		quotes[2];
	char	**res;

	i = 0;
	res = calloc(sizeof(char *), (ft_matrixlen(s) + 1));
	while (s[i])
	{
		s[i] = ft_expndvar(s[i], -1, quotes, prompt);
		s[i] = ft_expandpath(s[i], -1, quotes, ft_getenv("HOME", prompt->envp,
					4));
		res[i] = calloc(sizeof(char), ft_strlen_special(s[i]) + 1);
		res[i] = ft_split_trim_core(res, s, i);
		i++;
	}
	return (res);
}
