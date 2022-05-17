/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 21:11:19 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/04/19 21:12:00 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_open_pipes(int argc)
{
	int	(*pipefd)[2];
	int	i;

	pipefd = malloc(sizeof(int [argc - 4][2]));
	if (pipefd == NULL)
		ft_error_errno(NULL);
	i = 0;
	while (i < argc - 4)
	{
		if (pipe(*(pipefd + i)) < 0)
			ft_error_errno(NULL);
		i++;
	}
	return (pipefd);
}
