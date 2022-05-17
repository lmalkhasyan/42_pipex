/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:04:46 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/04/20 20:50:53 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>

typedef struct s_main
{
	int		argc;
	char	**argv;
	char	**envp;
}	t_main;

/* Main functions of project */
void	ft_pipex(t_main m);

/* Additional Functions */
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);

/* Error Handling */
void	ft_error(char *s, char *str);
void	ft_error_errno(char *s);

/* Getting cmd name from argv */
char	*ft_getcmd(char *str);

/* Getting Paths from envp and checking [cmd] file exec and existance */
char	**ft_getpaths(char *envp[]);
char	**ft_flags(char *str, char **envp);
char	*ft_exec(char **paths, char *cmd);

/*Free Functions */
void	ft_free_array(char **arr);
void	ft_free_matrix(char ***matrix);

/* Check File R_OK */
void	ft_check_file(char *path);

/* Close all pipes */
void	ft_close_pipes(int argc, int (*pipefd)[2]);

/* Open all pipes */
void	*ft_open_pipes(int argc);

/* Redirections of Pipes */
void	ft_first_cmd(t_main m, int (*pipefd)[2]);
void	ft_last_cmd(t_main m, int (*pipefd)[2]);
void	ft_middle_cmd(t_main m, int (*pipefd)[2], int i);

/* close all Pipes and wait childs */
void	ft_close_wait(int argc, int (*pipefd)[2]);
#endif
