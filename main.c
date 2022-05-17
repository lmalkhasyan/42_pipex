/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:10:15 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/04/20 20:49:40 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_main	m;

	if (argc < 5)
	{
		errno = EINVAL;
		ft_error_errno(NULL);
	}
	m = (t_main){.argc = argc, .argv = argv, .envp = envp};
	ft_pipex(m);
	return (0);
}
