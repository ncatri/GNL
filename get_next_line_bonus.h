/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 08:31:19 by ncatrien          #+#    #+#             */
/*   Updated: 2020/12/10 13:47:13 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
}				t_file;

typedef	struct	s_list
{
	t_file			*content;
	struct s_list	*next;
}				t_list;

typedef	struct	s_buf
{
	char	*tmp;
	size_t	position;
	size_t	size;
}				t_buf;

int				free_ret(void *ptr, int value);
t_file			*open_f(int fd);
int				get_char(t_file *f);
int				append(char **buf, size_t *pos_ptr, size_t *size_ptr, \
							char c);
void			ft_lstadd_front(t_list **alst, t_list *new);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstfind(t_list **alst, int fd_target);
int				ft_lstdelone(t_list **alst, int fd_target);
int				get_next_line(int fd, char **line);
void			*ft_memcpy(void *dst, const void *src, size_t n);

#endif
