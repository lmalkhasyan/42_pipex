/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:56:52 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/04/14 23:30:08 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_array(char **arr)
{
	if (!arr || !*arr)
		return ;
	free(*arr);
	*arr = NULL;
}

void	ft_free_matrix(char ***matrix)
{
	int	i;

	if (!matrix || !*matrix)
		return ;
	i = -1;
	while ((*matrix)[++i])
	{
		ft_free_array(*matrix + i);
	}
	free(*matrix);
	*matrix = NULL;
}
