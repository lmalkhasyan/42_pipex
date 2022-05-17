/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:15:51 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/03/13 17:15:51 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (*s)
	{
		counter++;
		s++;
	}
	return (counter);
}
