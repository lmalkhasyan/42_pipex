/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:24:53 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/04/20 20:37:51 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_file(char *path)
{
	int	ac;

	ac = access(path, R_OK);
	if (ac == -1)
		ft_error_errno(path);
}
