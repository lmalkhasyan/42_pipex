/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:29:34 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/04/19 23:08:09 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_pipes(int argc, int (*pipefd)[2])
{
	int	i;

	i = 0;
	while (i < argc - 4)
	{
		if (close(pipefd[i][0]) == -1)
			ft_error_errno(NULL);
		if (close(pipefd[i][1]) == -1)
			ft_error_errno(NULL);
		i++;
	}
	free(pipefd);
}

void	ft_close_wait(int argc, int (*pipefd)[2])
{
	ft_close_pipes(argc, pipefd);
	while (wait(NULL) > 0)
		;
}
