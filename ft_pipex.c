/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:47:56 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/04/20 20:49:00 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex(t_main m)
{
	int		i;
	pid_t	pid;
	int		(*pipefd)[2];

	i = 0;
	pipefd = ft_open_pipes(m.argc);
	while (i < m.argc - 3)
	{
		pid = fork();
		if (pid == -1)
			ft_error_errno(NULL);
		else if (pid == 0)
		{
			if (i == 0)
				ft_first_cmd(m, pipefd);
			else if (i == m.argc - 4)
				ft_last_cmd(m, pipefd);
			else
				ft_middle_cmd(m, pipefd, i);
		}
		i++;
	}
	if (pid > 0)
		ft_close_wait(m.argc, pipefd);
}
