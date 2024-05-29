/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_node_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:40:59 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/16 17:36:41 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int		g_stat;

t_mini	*ft_get_out1(t_mini *nd, char **av, int *i)
{
	char	*nlerr;
	int		flg[2];

	flg[0] = 1;
	flg[1] = 0;
	nlerr = "minishell: syntax error near unexpected token `newline'";
	(*i)++;
	if (av[*i])
		nd->outfile = ft_getfd(nd->outfile, av[*i], flg);
	if (!av[*i] || nd->outfile == -1)
	{
		*i = -1;
		if (nd->outfile != -1)
		{
			ft_putendl_fd(nlerr, 2);
			g_stat = 2;
		}
		else
			g_stat = 1;
	}
	return (nd);
}

t_mini	*ft_get_out2(t_mini *nd, char **av, int *i)
{
	char	*nlerr;
	int		flg[2];

	flg[0] = 1;
	flg[1] = 1;
	nlerr = "minishell: syntax error near unexpected token `newline'";
	(*i)++;
	if (av[*i])
		nd->outfile = ft_getfd(nd->outfile, av[*i], flg);
	if (!av[*i] || nd->outfile == -1)
	{
		*i = -1;
		if (nd->outfile != -1)
		{
			ft_putendl_fd(nlerr, 2);
			g_stat = 2;
		}
		else
			g_stat = 1;
	}
	return (nd);
}

t_mini	*ft_get_in1(t_mini *nd, char **av, int *i)
{
	char	*nlerr;
	int		flg[2];

	flg[0] = 0;
	flg[1] = 0;
	nlerr = "minishell: syntax error near unexpected token `newline'";
	(*i)++;
	if (av[*i])
		nd->infile = ft_getfd(nd->infile, av[*i], flg);
	if (!av[*i] || nd->infile == -1)
	{
		*i = -1;
		if (nd->infile != -1)
		{
			ft_putendl_fd(nlerr, 2);
			g_stat = 2;
		}
		else
			g_stat = 1;
	}
	return (nd);
}

t_mini	*ft_get_in2(t_mini *nd, char **av, int *i)
{
	char	*aux[2];
	char	*nlerr;
	char	*str[2];

	str[0] = NULL;
	str[1] = NULL;
	aux[0] = NULL;
	aux[1] = "minishell: warning: here-document delimited by end-of-file";
	nlerr = "minishell: syntax error near unexpected token `newline'";
	(*i)++;
	if (av[*i])
	{
		aux[0] = av[*i];
		nd->infile = ft_get_red_doc(str, aux);
	}
	if (!av[*i] || nd->infile == -1)
	{
		*i = -1;
		if (nd->infile != -1)
		{
			ft_putendl_fd(nlerr, 2);
			g_stat = 2;
		}
	}
	return (nd);
}
