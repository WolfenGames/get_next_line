/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:10:54 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/30 18:16:30 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static char		*joinchr(char *s1, char c)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1 || !c)
		return (NULL);
	j = ft_strlen(s1);
	new = ft_strnew(j + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < j)
		*(new + i) = *(s1 + i);
	*(new + i) = c;
	return (new);
}

static	int		contentcopy(char **dst, char *src, char c)
{
	int		i;
	int		pos;
	int		cc;

	i = -1;
	cc = 0;
	while (src[++i])
		if (src[i] == c)
			break ;
	pos = i;
	if (!(*dst = ft_strnew(i)))
		return (0);
	while (src[cc] && cc < i)
	{
		if (!(*dst = joinchr(*dst, src[cc])))
			return (0);
		cc++;
	}
	return (pos);
}

static t_list	*get_file(t_list **file, int fd)
{
	t_list	*tmp;
	
	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

int				get_next_line(int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	int				i;
	static t_list	*files;
	t_list			*c_file;

	if (fd < 0 || !line)
		return (0);
	c_file = get_file(&files, fd);
	MALLCHECK((*line = ft_strnew(1)));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		MALLCHECK((c_file->content = ft_strjoin(c_file->content, buf)));
		if (ft_strrchr(buf, '\n'))
				break ;
	}
	i = contentcopy(line, c_file->content, '\n');
	(i < (int)ft_strlen(c_file->content)) ? c_file->content += (i + 1) :
		ft_strclr(c_file->content);
	return (1);	
}
