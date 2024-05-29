/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:10:42 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/17 16:30:03 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_wordcount_core(char *str, int *ij)
{
	while (str[ij[0]] == ' ')
	{
		if (str[ij[0] + 1] == '\0')
			return (ij[1]);
		ij[0]++;
	}
	if (str[ij[0]] == '"' || str[ij[0]] == 39)
	{
		ij[0]++;
		while (str[ij[0]] != '"' && str[ij[0]] != 39)
		{
			if (str[ij[0]] == '\0')
				return (ij[1]);
			ij[0]++;
		}
		ij[1]++;
	}
	else
		ij[1]++;
	return (ij[1]);
}

int	ft_wordcount(char *str)
{
	int	ij[2];

	ij[0] = 0;
	ij[1] = 1;
	if (!str)
		return (0);
	while (str[ij[0]] == ' ')
		ij[0]++;
	while (str[ij[0]])
	{
		if (str[ij[0]] == ' ')
		{
			ij[1] = ft_wordcount_core(str, ij);
			if (str[ij[0] + 1] == '\0')
				return (ij[1]);
			if (str[ij[0]] == '\0')
				return (ij[1]);
		}
		ij[0]++;
	}
	return (ij[1]);
}

int	ft_split_wlen(char *prompt, int *i)
{
	int	wlen;

	wlen = 0;
	while (prompt[i[0]] && prompt[i[0]] != ' ')
	{
		if (prompt[i[0]] == '"' || prompt[i[0]] == 39)
			ft_wlen_check(prompt, i, &wlen);
		else if (prompt[i[0]] == '|' || prompt[i[0]] == '>'
			|| prompt[i[0]] == '<')
		{
			wlen++;
			if (prompt[i[0] + 1] && (prompt[i[0] + 1] == '<' || prompt[i[0]
						+ 1] == '>'))
			{
				wlen++;
				i[0]++;
			}
			break ;
		}
		else
			wlen++;
		i[0]++;
	}
	return (wlen);
}

char	**ft_split_all_core(char *prompt, char **res, int *i)
{
	int	wlen;
	int	wstart;

	wstart = 0;
	while (prompt[i[0]])
	{
		i[2] = 0;
		while (prompt[i[0]] && prompt[i[0]] == ' ')
			i[0]++;
		if (prompt[i[0]] == '\0')
			break ;
		wstart = i[0];
		wlen = ft_split_wlen(prompt, i);
		res[i[1]] = malloc(sizeof(char) * (wlen + 1));
		while (i[2] < wlen)
			res[i[1]][i[2]++] = prompt[wstart++];
		res[i[1]][i[2]] = '\0';
		i[1]++;
		if (prompt[i[0]] == '\0')
			break ;
		i[0]++;
	}
	res[i[1]] = '\0';
	return (res);
}

char	**ft_split_all(char *prompt)
{
	int		i[3];
	int		wc;
	char	**res;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	wc = ft_wordcount(prompt);
	if (wc == 0)
		return (NULL);
	res = malloc(sizeof(char *) * (wc + 1));
	return (ft_split_all_core(prompt, res, i));
}
