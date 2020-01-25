/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:52:59 by lseema            #+#    #+#             */
/*   Updated: 2020/01/25 18:07:21 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!(p = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while ((i <= size))
	{
		*(p + i) = '\0';
		i++;
	}
	return (p);
}
