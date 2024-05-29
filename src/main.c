/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:23:09 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/16 19:27:20 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_stat;

void	ft_signal(int signal)
{
	if (signal == SIGINT)
	{
		g_stat = 130;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

void	ft_split_row(char *output, t_prompt *prompt)
{
	char	**arr;
	char	**temp;

	temp = ft_split_all(output);
	arr = ft_split_trim(temp, prompt);
	prompt->cmds = ft_take_cmd(arr, temp, -1);
}

void	ft_prompt_destroy(char *out, t_prompt prompt)
{
	free(out);
	ft_free_matrix(&prompt.envp);
	ft_putendl_fd("exit", 1);
}

char	*ft_getprompt(t_prompt prompt)
{
	char	*temp;
	char	*temp2;
	char	*aux;

	temp = ft_get_usr(prompt);
	temp2 = ft_strjoin(temp, "@minishell");
	free(temp);
	aux = ft_gethome(prompt);
	temp = ft_strjoin(temp2, aux);
	free(aux);
	free(temp2);
	temp2 = ft_strjoin(temp, "$ ");
	free(temp);
	return (temp2);
}

int	main(int argc, char **argv, char **envp)
{
	char		*out;
	char		*str;
	t_prompt	prompt;

	prompt = ft_prompt(argv, envp);
	while (argc)
	{
		signal(SIGINT, ft_signal);
		signal(SIGQUIT, SIG_IGN);
		str = ft_getprompt(prompt);
		out = readline(str);
		free(str);
		if (!out)
		{
			ft_prompt_destroy(out, prompt);
			break ;
		}
		add_history(out);
		ft_split_row(out, &prompt);
		if (!ft_check_prompt(&prompt))
			break ;
	}
	if (out)
		free(out);
	exit(g_stat);
}
