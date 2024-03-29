/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 12:55:32 by ncatrien          #+#    #+#             */
/*   Updated: 2020/12/10 16:09:29 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define FDS_LIM	256
# define BUF_LINE_LIM	1

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_file
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	size_t	position;
	size_t	size;
	int		eof;
	int		bad;
}				t_file;

typedef struct	s_buf
{
	char	*tmp;
	size_t	pos;
	size_t	size;
}				t_buf;

int				get_next_line(int fd, char **line);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				free_ret(void *ptr, int value);
t_file			*open_f(int fd);
int				get_char(t_file *f);
int				append(char **buf, size_t *pos_ptr, size_t *size_ptr, char c);

#endif
