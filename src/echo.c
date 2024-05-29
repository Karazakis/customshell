/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:22:29 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/16 16:22:10 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_stat;

int	ft_echo(t_list *cmd)
{
	int		flag[3];
	char	**av;
	t_mini	*nd_list;

	flag[2] = 0;
	flag[0] = 1;
	flag[1] = 0;
	nd_list = cmd->content;
	av = nd_list->full_cmd;
	while (av && av[++flag[2]])
	{
		if (flag[1] == 0 && !ft_strncmp(av[flag[2]], "-n", 2)
			&& ft_strlen(av[flag[2]]) == 2)
			flag[0] = 0;
		else
		{
			flag[1] = 1;
			printf("%s", av[flag[2]]);
			if (av[flag[2] + 1])
				printf(" ");
		}
	}
	if (flag[0] == 1)
		printf("\n");
	return (0);
}
