/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 08:32:20 by ncatrien          #+#    #+#             */
/*   Updated: 2020/12/08 09:21:56 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		free_and_return(void *ptr, int value)
{
	free(ptr);
	return (value);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_ptr;
	size_t	i;

	if (dst == 0 && src == 0)
		return (NULL);
	dst_ptr = (char*)dst;
	i = -1;
	while (++i < n)
	{
		*dst_ptr = *((char*)src + i);
		dst_ptr++;
	}
	return (dst);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	if (!content || !(ptr = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	ptr->content = content;
	ptr->next = (NULL);
	return (ptr);
}

t_list	*ft_lstfind(t_list **alst, int fd_target)
{
	t_list	*cursor;

	if (alst && fd_target >= 0)
	{
		cursor = *alst;
		while (cursor)
		{
			if (cursor->content->fd == fd_target)
				return (cursor);
			cursor = cursor->next;
		}
	}
	return (NULL);
}