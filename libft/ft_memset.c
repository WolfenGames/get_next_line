/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:37:33 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/24 14:39:25 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_void	ft_memset(void *str, int c, size_t n)
{
	t_str	new;
	size_t	i;
	
	i = 0;
	new = str;
	while (i < n)
	{
		new[i] = c;
		i++;
	}
	return (new);
}
