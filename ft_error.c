/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:32:33 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/04/15 16:57:26 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *s, char *str)
{
	if (str && *str)
	{
		write(2, str, ft_strlen(str));
		write(2, ": ", 2);
		write(2, s, ft_strlen(s));
		write(2, "\n", 1);
		free(str);
		exit(EXIT_FAILURE);
	}
	else
	{
		write(2, s, ft_strlen(s));
		exit(EXIT_FAILURE);
	}
}

void	ft_error_errno(char *path)
{
	if (errno)
	{
		perror(path);
		exit (EXIT_FAILURE);
	}
	else
	{
		write(2, path, ft_strlen(path));
		exit(EXIT_FAILURE);
	}
}
