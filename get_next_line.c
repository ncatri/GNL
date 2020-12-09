/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:13:38 by ncatrien          #+#    #+#             */
/*   Updated: 2020/12/09 13:51:08 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			return (free_and_return(f, -1));
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
	static	t_file	*file;
	char			c;
	char			*tmp;
	size_t			tmp_pos;
	size_t			tmp_size;

	if (fd < 0 || fd >= FDS_LIM || !line)
		return (-1);
	if ((tmp = malloc(BUF_LINE_LIM * sizeof(char))) == 0)
		return (-1);
	tmp_pos = 0;
	tmp_size = BUF_LINE_LIM;
	if (file == 0)
		file = open_f(fd);
	while ((c = get_char(file)) != '\n' && file->eof == 0)
		if (c == -1 || !append_char(&tmp, &tmp_pos, &tmp_size, c))
			return (free_and_return(tmp, -1));
	if (!append_char(&tmp, &tmp_pos, &tmp_size, '\0'))
		return (free_and_return(tmp, -1));
	*line = tmp;
	if (file->eof)
	{
		free(file);
		file = 0;
		return (0);
	}
	return (1);
}
