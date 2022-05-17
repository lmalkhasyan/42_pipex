/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:21:51 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/04/19 16:17:59 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/* Getting (Malloced)flags from argv[1] */
char	**ft_flags(char *str, char **envp)
{
	char	**flags;
	char	*temp;

	if (!str)
		ft_error("Cmd dont exist", NULL);
	flags = ft_split(str, ' ');
	temp = ft_exec(ft_getpaths(envp), flags[0]);
	ft_free_array(&flags[0]);
	*flags = temp;
	if (!flags || !(*flags) || !(**flags))
	{
		ft_free_matrix(&flags);
		return (NULL);
	}
	return (flags);
}
