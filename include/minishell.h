/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:33:36 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/19 14:12:04 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <curses.h>
#include <dirent.h>
#include <fcntl.h>
#include <pthread.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <unistd.h>

extern int	g_stat;

typedef struct s_prompt
{
	t_list	*cmds;
	char	**envp;
	pid_t	pid;
}			t_prompt;

typedef struct s_mini
{
	char	**full_cmd;
	char	*full_path;
	int		infile;
	int		outfile;
}			t_mini;

enum		e_mini_error
{
	QUOTE = 1,
	NDIR = 2,
	NPERM = 3,
	NCMD = 6,
	DUPERR = 7,
	FORKERR = 8,
	PIPERR = 9,
	PIPENDERR = 10,
	MEM = 11,
	IS_DIR = 12,
	NOT_DIR = 13
};

#define READ_END 0
#define WRITE_END 1

char		*ft_get_red_str(char *str[2], size_t len, char *limit, char *warn);
int			ft_get_red_doc(char *str[2], char **aux);
t_mini		*ft_init(void);
int			ft_getfd(int oldfd, char *path, int flags[2]);
t_mini		*ft_get_in2(t_mini *node, char **args, int *i);
t_mini		*ft_get_in1(t_mini *node, char **args, int *i);
t_mini		*ft_get_out2(t_mini *node, char **args, int *i);
t_mini		*ft_get_out1(t_mini *node, char **args, int *i);
t_list		*ft_take_cmd(char **args, char **pargs, int i);
char		**ft_split_all(char *prompt);
char		**ft_split_trim(char **s, t_prompt *prompt);
char		*ft_expndvar(char *str, int i, int quotes[2], t_prompt *prompt);
char		*ft_expandpath(char *str, int i, int quotes[2], char *var);
void		ft_print_ordered_env(char **env, int ij[2]);
int			ft_export_check(t_list *cmd, char **a, int n);
char		*ft_getenv(char *var, char **envp, int n);
char		**ft_setenv(char *var, char *value, char **envp, int n);
int			var_in_envp(char *argv, char **envp, int ij[2]);
int			ft_export(t_prompt *prompt);
char		**ft_matrix_replace_in(char ***big, char **small, int n);
void		*ft_perror(int err_type, char *param, int err);
void		ft_cderror(char **str[2]);
int			ft_is_builtin(t_mini *n);
void		*ft_redir(t_list *cmd, int fd[2]);
void		ft_builtin(t_prompt *prompt, t_mini *n, int l, t_list *cmd);
void		*ft_child(t_prompt *prompt, t_list *cmd, int fd[2]);
void		ft_fork(t_prompt *prompt, t_list *cmd, int fd[2]);
int			exec_proc(t_prompt *prompt, t_list *cmd, int *is_exit, int n);
int			is_builtin(t_mini *n);
void		ft_updt_out(char ***matrix, int fd);
void		ft_exec_cstm(char ***out, char *full, char *args, char **envp);
char		*ft_gethome(t_prompt prompt);
char		*ft_get_usr(t_prompt prompt);
char		*ft_getprompt(t_prompt prompt);
char		*ft_findcmd(char **env_path, char *cmd, char *full_path);
void		ft_getpid(t_prompt *p);
t_prompt	ft_initvars(t_prompt prompt, char *str, char **argv);
t_prompt	ft_prompt(char **argv, char **envp);
void		*ft_check_prompt(t_prompt *p);
void		ft_freecontent(void *content);
void		ft_signal(int signal);
void		ft_quicksort(char ***arr, int low, int high);
int			ft_unset(t_prompt *prompt);
int			ft_cd(t_prompt *p);
int			ft_exit(t_list *cmd, int *is_exit);
int			ft_echo(t_list *cmd);
int			ft_pwd(void);
int			ft_putmatrix_special_fd(char **m, int nl, int fd);
void		ft_wlen_check(char *prompt, int *i, int *wlen);
