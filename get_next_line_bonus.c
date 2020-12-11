/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 08:30:14 by ncatrien          #+#    #+#             */
/*   Updated: 2020/12/10 14:50:30 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		free_and_return(void *ptr, int value)
{
	free(ptr);
	return (value);
}

t_file	*open_f(int fd)
{
	t_file *fpt;

	if (!(fpt = malloc(1 * sizeof(t_file))))
		return (NULL);
	fpt->fd = fd;
	fpt->position = 0;
	fpt->size = 0;
	fpt->eof = 0;
	return (fpt);
}

int		get_char(t_file *f)
{
	char	c;
	ssize_t read_ret;

	if (!f)
		return (-1);
	if (f->position >= f->size)
	{
		read_ret = read(f->fd, f->buffer, BUFFER_SIZE);
		if (read_ret > 0)
		{
			f->position = 0;
			f->size = read_ret;
		}
		else if (read_ret == 0)
		{
			f->eof = 1;
			return (0);
		}
		else
			return (-1);
	}
	c = f->buffer[f->position];
	f->position++;
	return (c);
}

int		append_char(char **buf, size_t *pos_ptr, size_t *size_ptr, char c)
{
	char	*tmp;

	if (*pos_ptr >= *size_ptr)
	{
		if (!(tmp = malloc(sizeof(char) * (*size_ptr + BUF_LINE_LIM))))
			return (free_and_return(*buf, 0));
		ft_memcpy(tmp, *buf, *size_ptr);
		*size_ptr = *size_ptr + BUF_LINE_LIM;
		free(*buf);
		*buf = tmp;
	}
	(*buf)[*pos_ptr] = c;
	(*pos_ptr)++;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static	t_list	*lst_files;
	char			c;
	t_file			*file;
	t_buf			b;

	if (fd < 0 || !line || !(b.tmp = malloc(sizeof(char))) || BUFFER_SIZE <= 0)
		return (-1);
	b.position = 0;
	b.size = BUF_LINE_LIM;
	if (!ft_lstfind(&lst_files, fd))
		ft_lstadd_front(&lst_files, ft_lstnew(open_f(fd)));
	if (!(file = (ft_lstfind(&lst_files, fd))->content))
		return (-1);
	while ((c = get_char(file)) != '\n' && file->eof == 0)
		if (c == -1 || !append_char(&b.tmp, &b.position, &b.size, c))
		{
			ft_lstdelone(&lst_files, fd);
			return (free_and_return(b.tmp, -1));
		}
	if (!append_char(&b.tmp, &b.position, &b.size, '\0'))
		return (free_and_return(b.tmp, -1));
	*line = b.tmp;
	if (file->eof && ft_lstdelone(&lst_files, fd))
		return (0);
	return (1);
}
