/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:41:59 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 10:44:49 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s1;

	s1 = (char *)s;
	i = 0;
	while (s1[i])
		i++;
	while (i >= 0)
	{
		if (s1[i] == (char)c)
			return (&s1[i]);
		i--;
	}
	return (NULL);
}
