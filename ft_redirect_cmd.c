/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:02:56 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/12 18:56:50 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_first_cmd(t_main m, int (*pipefd)[2])
{
	int		in;
	char	*execpath;

	ft_check_file(m.argv[1]);
	in = open(m.argv[1], O_RDONLY);
	if (in == -1)
		ft_error_errno(NULL);
	// printf ("in = %d, out = %d\n", in , pipefd[0][1]);
	execpath = ft_exec(ft_getpaths(m.envp), ft_getcmd(m.argv[0 + 2]));
	if (dup2(in, STDIN_FILENO) == -1)
		ft_error_errno(NULL);
	if (dup2(pipefd[0][1], STDOUT_FILENO) == -1)
		ft_error_errno(NULL);
	ft_close_pipes(m.argc, pipefd);
	close(in);
	if (execve(execpath, ft_flags(m.argv[0 + 2], m.envp), m.envp) == -1)
		ft_error_errno(NULL);
}

void	ft_last_cmd(t_main m, int (*pipefd)[2])
{
	int		out;
	char	*execpath;

	out = open(m.argv[m.argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (out == -1)
		ft_error_errno(NULL);
	// printf ("out = %d, in = %d\n", out , pipefd[(m.argc - 4) - 1][0]);
	execpath = ft_exec(ft_getpaths(m.envp), ft_getcmd(m.argv[m.argc - 4 + 2]));
	if (dup2(pipefd[(m.argc - 4) - 1][0], STDIN_FILENO) == -1)
		ft_error_errno(NULL);
	if (dup2(out, STDOUT_FILENO) == -1)
		ft_error_errno(NULL);
	ft_close_pipes(m.argc, pipefd);
	close(out);
	if (execve(execpath, ft_flags(m.argv[(m.argc - 2)], m.envp), m.envp) == -1)
		ft_error_errno(NULL);
}

void	ft_middle_cmd(t_main m, int (*pipefd)[2], int i)
{
	char	*execpath;
	dprintf (2, "out = %d, in = %d ", pipefd[i - 1][0] ,pipefd[i][1]);
	execpath = ft_exec(ft_getpaths(m.envp), ft_getcmd(m.argv[i + 2]));
	if (dup2(pipefd[i - 1][0], STDIN_FILENO) == -1)
		ft_error_errno(NULL);
	if (dup2(pipefd[i][1], STDOUT_FILENO) == -1)
		ft_error_errno(NULL);
	ft_close_pipes(m.argc, pipefd);
	if (execve(execpath, ft_flags(m.argv[i + 2], m.envp), m.envp) == -1)
		ft_error_errno(NULL);
}
