/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:21:51 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/04/18 15:46:16 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/* Getting cmd name from argv[1](malloced) */
char	*ft_getcmd(char *str)
{
	char	**splited;
	char	*cmd;

	if (!str)
		ft_error("argv[2] dont exist", NULL);
	splited = ft_split(str, ' ');
	if (!splited)
		ft_error("cant split cmd and args", NULL);
	cmd = ft_strdup(splited[0]);
	ft_free_matrix(&splited);
	if (!cmd)
		ft_error("cant allocate memory for cmd", NULL);
	return (cmd);
}
