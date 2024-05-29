/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_node_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:41:54 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/16 17:23:57 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int		g_stat;

char	*ft_get_red_str(char *str[2], size_t len, char *limit, char *warn)
{
	char	*temp;

	while (g_stat != 130 && (!str[0] || ft_strncmp(str[0], limit, len)
			|| ft_strlen(limit) != (int)len))
	{
		temp = str[1];
		str[1] = ft_strjoin(str[1], str[0]);
		free(temp);
		free(str[0]);
		str[0] = readline("> ");
		if (!str[0])
		{
			printf("%s (wanted `%s\')\n", warn, limit);
			break ;
		}
		temp = str[0];
		str[0] = ft_strjoin(str[0], "\n");
		free(temp);
		len = ft_strlen(str[0]) - 1;
	}
	free(str[0]);
	return (str[1]);
}

int	ft_get_red_doc(char *str[2], char **aux)
{
	int	fd[2];

	g_stat = 0;
	if (pipe(fd) == -1)
	{
		ft_perror(PIPERR, NULL, 1);
		return (-1);
	}
	str[1] = ft_get_red_str(str, 0, aux[0], aux[1]);
	write(fd[WRITE_END], str[1], ft_strlen(str[1]));
	free(str[1]);
	close(fd[WRITE_END]);
	if (g_stat == 130)
	{
		close(fd[READ_END]);
		return (-1);
	}
	return (fd[READ_END]);
}

t_mini	*ft_init(void)
{
	t_mini	*mini;

	mini = malloc(sizeof(t_mini));
	if (!mini)
		return (NULL);
	mini->full_cmd = NULL;
	mini->full_path = NULL;
	mini->infile = STDIN_FILENO;
	mini->outfile = STDOUT_FILENO;
	return (mini);
}

int	ft_getfd(int fd_old, char *path, int flg[2])
{
	int	fd;

	if (fd_old > 2)
		close(fd_old);
	if (!path)
		return (-1);
	if (access(path, F_OK) == -1 && !flg[0])
		ft_perror(NDIR, path, 127);
	else if (!flg[0] && access(path, R_OK) == -1)
		ft_perror(NPERM, path, 126);
	else if (flg[0] && access(path, W_OK) == -1 && access(path, F_OK) == 0)
		ft_perror(NPERM, path, 126);
	if (flg[0] && flg[1])
		fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0666);
	else if (flg[0] && !flg[1])
		fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	else if (!flg[0] && fd_old != -1)
		fd = open(path, O_RDONLY);
	else
		fd = fd_old;
	return (fd);
}
