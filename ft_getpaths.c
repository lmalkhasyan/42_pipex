/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpaths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:12:37 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/04/18 15:46:34 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Get all paths from envp variable splitted(Malloced) */
#include "pipex.h"

char	**ft_getpaths(char *envp[])
{
	char	**paths;

	if (!envp)
		ft_error("Env variable not set", NULL);
	while (*envp != 0)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			paths = ft_split((*envp + 5), ':');
			if (!paths)
				ft_error("cant allocate memory for paths", NULL);
			return (paths);
		}
		envp++;
	}
	return (NULL);
}
