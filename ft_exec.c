/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getexec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:22:20 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/04/19 16:40:04 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/* check all paths and returns full path of exec */
char	*ft_exec(char **paths, char *cmd)
{
	char	*fullpath;
	char	*temppath;
	int		ac;

	if (*cmd == '/')
		return (cmd);
	if (!paths)
		ft_error("Paths Don't exist", NULL);
	else if (!cmd)
		ft_error("CMD Don't exist", NULL);
	while (*paths != NULL)
	{
		temppath = ft_strjoin(*paths, "/");
		fullpath = ft_strjoin(temppath, cmd);
		free(temppath);
		ac = access(fullpath, (X_OK));
		if (ac == 0)
			return (fullpath);
		free(fullpath);
		paths++;
	}
	ft_error("command not found", cmd);
	return (fullpath);
}
