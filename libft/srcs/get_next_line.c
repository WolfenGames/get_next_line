/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:10:54 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/22 09:25:55 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		copyline(char *line, char *buf)
{
	unsigned int		count;

	count = 0;
	while (line[count] != '\n' && line[count])
		count++;
	if (ft_strlen(line) > count + 1)
	{
		buf = ft_strcpy(buf, &(line[count + 1]));
	}
	line[count] = '\0';
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	buff[FD_MAX + 1][BUFF_SIZE + 1] = {"\0"};
	char		*temp;
	int			error;

	error = 1;
	if (fd < 0 || fd > FD_MAX || !line || !(*line = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (buff[fd][0] != '\0')
		*line = ft_strcpy(*line, buff[fd]);
	ft_bzero(buff[fd], BUFF_SIZE);
	while (!(ft_strchr(*line, '\n')) && error > 0)
	{
		if ((error = read(fd, buff[fd], BUFF_SIZE)) > 0)
		{
			temp = *line;
			*line = ft_strjoin(*line, buff[fd]);
			free(temp);
			if (!*line)
				return (-1);
			ft_bzero(buff[fd], BUFF_SIZE);
		}
	}
	if (*line[0] != '\0' && error >= 0)
		return (copyline(*line, buff[fd]));
	return (error);
}
