/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:06:07 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/11 09:20:03 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_i(char const *str, int a)
{
	char	*temp;
	char	*join;

	temp = NULL;
	join = NULL;
	temp = join;
	join = ft_strjoin(str, ft_itoa(a));
	ft_putendl(join);
	free(join);
}
